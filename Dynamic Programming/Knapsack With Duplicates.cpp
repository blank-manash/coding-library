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

    int n,W;
    cin >> n, cin >> W;
    vi w(n),v(n);
    input(v,n); input(w,n);
    int dp[n][W+1];
    memset(dp,0,sizeof(dp));
    for( int i = 0; i < n; i++) {

        for( int j = 0; j <=W; j++) {

            int ans = 0;
            
            if( i > 0 ) {
                ans = max(ans,dp[i-1][j]);
            }
            if( j >= w[i]) {
                ans = max(ans,v[i]+dp[i][j-w[i]]);
            }

            dp[i][j] = ans;

        }
    }

    cout << dp[n-1][W];
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