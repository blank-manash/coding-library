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

void test() {

    int n,k;
    cin >> n >> k;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[1] = k;
    dp[2] = k*k;

    for( int i = 3; i <= n; i++ ) {

        dp[i] = (((dp[i-1] + dp[i-2])%mod)*(k-1))%mod;
    }
    //if(dp[n] == -1) dp[n] = 0; 
    cout << dp[n];
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