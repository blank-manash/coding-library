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

    int n,x,y,z;
    cin >> n;
    cin >> x >> y >> z;
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for( int i = 1; i <=n; i++ ) {

        int a = -1, b = -1, c = -1;
        if ( i >= x and dp[i-x] != -1) a = 1+dp[i-x];
        if ( i >= y and dp[i-y] != -1) b = 1+dp[i-y];
        if ( i >= z and dp[i-z] != -1) c = 1+dp[i-z];

        dp[i] = max({a,b,c});
    }

    dp[n] == -1 ? cout << 0 : cout << dp[n];
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