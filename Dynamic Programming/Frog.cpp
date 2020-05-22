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

    int n;
    cin >> n;
    vi arr = {1,2,3};
    vi dp(n+1,0);
    dp[0] = 1;
    for( int i = 0; i <= n; i++) {

        if( dp[i] == 0 ) continue;
        if( i+1 <= n ) dp[i+1] += dp[i];
        if( i+2 <= n ) dp[i+2] += dp[i];
        if( i+3 <= n ) dp[i+3] += dp[i];
    }
    //for ( int x : dp ) cout << x <<" ";
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