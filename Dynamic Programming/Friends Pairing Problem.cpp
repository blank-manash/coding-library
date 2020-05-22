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

    int n;
    cin >> n;
    vi dp(n+1);
    dp[1] = 1;
    dp[0] = 1;
    for( int i = 2; i <=n; i++ ) {

        dp[i] = ((((i-1)%mod)*(dp[i-2])%mod)%mod + dp[i-1]%mod)%mod;
    }
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