#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define int long long
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;
const int mod = 1e9+7;
// ===================== MANASH =================== //
int n,r;

void test() {

    cin >> n >> r;

    if ( r > n ) {
        cout << -1;
        return;
    }
    vector<vi> dp(n+1,vi(n+1,-1));

    for( int i = 1; i <= n; i++) {
        for( int j = 0; j <= i; j++) {

            if( j == 1 ) {

                dp[i][j] = i;
                continue;
            }

            if( j == 0 or j == i) {
                dp[i][j] = 1;
                continue;
            }
            else dp[i][j] = (dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
        }
    }

    cout << dp[n][r];
    
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