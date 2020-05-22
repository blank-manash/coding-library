#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    vector<vector<int>> dp(n+1,vi(n+1,0));
    int maxLen = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if( i == 0 or j == 0) {
                dp[i][j] = 0;
            }
            else if( s[i-1] == s2[j-1] and i != j) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout << dp[n][n];
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