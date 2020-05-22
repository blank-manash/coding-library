#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
#define int long long 
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;
const int mod = 1e9+7;
// ===================== MANASH =================== //

void test() {

    int n;
    cin >> n;
    vi dp(n+1,0);
    dp[0] = dp[1] = 0;
    dp[2] = 1; dp[3] = 2;

    for( int i = 4; i <= n; i++) {

        dp[i] += (dp[i-1]*(i))%mod;
        if(i&1) dp[i]--;
        else dp[i]++;
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