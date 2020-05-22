// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/


bool is_k_palin(string s,int k)
{
    int n = s.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for( int i = 0; i < n; i++) dp[i][i] = 1;

    for( int l = 2; l <= n; l++) {
        for( int i = 0; i < n; i++) {

            int j = l+i-1;
            if(j > n) continue;
            if (s[i] == s[j] and l == 2 ) dp[i][j] = 2;
            else if ( s[i] == s[j] ) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
    }

    return k >= dp[0][n-1];
}