// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool mycomp (struct val p1, struct val p2) {
    return (p2.second > p1. second);
}

int maxChainLen(struct val p[],int n)
{
    
    int dp[n];
    for(int i=0;i<n;i++) dp[i] = 1;
    sort(p,p+n,mycomp);
    for( int i = 1; i<n; i++) {
        
        for(int j = 0; j<i; j++) {
            //int x1 = p[j].first;
            int y1 = p[j].second;
            int x2 = p[i].first;
            //int y2 = p[i].second;
            //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
            if(x2 > y1) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int ans = -1;
    for( int i = 0; i<n ; i++) ans = max(ans,dp[i]);
    return ans;
//Your code here
}