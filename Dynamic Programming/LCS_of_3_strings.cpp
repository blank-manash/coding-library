#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;
// ===================== MANASH =================== //

void test() {

    int n,k,m;
    cin >> n >> k >> m;
    string a,b,c;
    cin >> a >> b >> c;
    vector<vector<vi>> dp(n+1,vector<vi>(k+1,vi(m+1)));
    
    for( int i = 0; i <= n; i++) {
        for ( int j = 0; j <= k; j++) {
            for ( int p = 0; p <= m; p++) {

                if( i == 0 or j == 0 or p == 0) dp[i][j][p] = 0;
                else if ( a[i-1] == b[j-1] and b[j-1] == c[p-1]) dp[i][j][p] = 1+dp[i-1][j-1][p-1];
                else dp[i][j][p] = max({dp[i-1][j][p],dp[i][j-1][p],dp[i][j][p-1]});
            }
        }
    }

    cout << dp[n][k][m];
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