// { Driver Code Starts
#include<bits/stdc++.h>
#define N 105
using namespace std;
int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

int *mergeKArrays(int arr[][N], int k)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, \
    greater<pair<int,pair<int,int>>>> q;

    for(int i = 0; i < k; i++) {
        q.push({arr[i][0],{i,0}});
    }
    int *myarray = new int[k*k];

    for(int i = 0; i < k*k; i++) {
        auto p = q.top(); q.pop();
        if (p.second.second != k-1)
            q.push({arr[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
        myarray[i] = p.first;
    }

    return myarray;

//code here
}