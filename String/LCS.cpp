#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    string ss;
    cin >> ss;
    vector<vector<int>> dp(n+1,vi(m+1,0));

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=m; j++) {

            if( s[i-1] == ss[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[n][m];
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