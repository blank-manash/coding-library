// { Driver Code Starts
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

void findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}

// } Driver Code Ends
// you are required to complete this function 
// function should print the required range



void findSmallestRange(int arr[][N], int n, int k)
{
    
}