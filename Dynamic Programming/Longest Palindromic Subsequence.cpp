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

    int n; cin >> n;
    string s; cin >> s;
    int dp[n][n];

    memset(dp,1,sizeof(dp));

    for(int l = 2; l <= n; l++) {
        for( int i = 0; i < n-l+1; i++) {

            int j = i+l-1;

            if( s[i] == s[j] and l == 2 ) dp[i][j] = 2;
            else if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }

    cout << dp[0][n-1];
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