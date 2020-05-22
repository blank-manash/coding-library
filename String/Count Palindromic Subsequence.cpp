#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

int countP(string s ) {
    
    int n = s.size();
    vector<vector<int>> dp(n,vi(n,0));
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for( int L = 2; L <=n; L++) {

        for(int i = 0; i < n; i++) {
            
            int k = L+i-1;
            if( k > n-1 ) continue;
            if( i == k ) {
                dp[i][i] = 1;
                continue;
            }
            else if (s[i] == s[k]) {
                dp[i][k] = 1+dp[i+1][k]+dp[i][k-1];
            }
            else dp[i][k] = dp[i+1][k]+dp[i][k-1]-dp[i+1][k-1];
        }
    }

    return dp[0][n-1];
}


void test() {

    string s;
    cin >> s;
    cout << countP(s);
    
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}