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

    int n,m;
    cin >> n >> m;
    vector<vi> arr(n,vi(m));
    for( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for( int i = 0; i < n; i++) dp[i][0] = arr[i][0];

    for( int j = 1; j < m; j++) {
        for( int i = 0; i < n; i++) {
            
            // j-1 -> i,i-1,i+1;
            int ans = -1;
            if( i > 0 ) ans = max(ans,dp[i-1][j-1]);
            ans = max(ans,dp[i][j-1]);
            if( i+1 < n ) ans = max(ans,dp[i+1][j-1]);
            dp[i][j] = arr[i][j]+ans;
        }
    }

    int ans = 0;
    for( int i = 0; i < n; i++) ans = max(ans,dp[i][m-1]);
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