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

    int n,m; string a,b;
    cin >> n >> m >> a >> b;

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int ans = -1;
    for( int i = 0; i <= n; i++) {
        for ( int j = 0; j <=m; j++) {
            if( i == 0 or j == 0) continue;
            if ( a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]);
            ans = max(ans,dp[i][j]);
        }
    }

    cout << ans;
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