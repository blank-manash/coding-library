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
// ===================== MANASH =================== //

int dp[105];

void test() {

    int n;
    cin >> n;
    cout << dp[n];

}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    memset(dp,0,sizeof(dp));
    dp[0] = dp[1] = 1;
    for( int i = 2; i < 105; i++) {
        for( int j = 0; j < i; j++) {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}