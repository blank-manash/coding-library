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

    string s;
    cin >> s;
    int n = s.size();
    int dp[n];
    memset(dp,0,sizeof(dp));
    bool p[n][n];
    memset(p,false,sizeof(p));
    for( int i = 0; i < n; i++) p[i][i] = true;
    for( int l = 2; l <=n; l++) {
        
        for( int i = 0; i < n; i++) {
            int j = i+l-1;
            if( j > n-1 ) continue;

            if (l == 2 and s[i] == s[j]) p[i][j] = true;
            else p[i][j] = s[i] == s[j] and p[i+1][j-1];
        }
    }
    // METHOD TO FIND if p[i][j] is palindrome.

    // Since now pali is counted now check length.

    for( int i = 0; i < n; i++) {

        if(p[0][i]) continue;
        dp[i] = inf;
        for( int j = 0; j < i; j++) {

            if (p[j+1][i] and dp[j]+1 < dp[i]) dp[i] = dp[j]+1;
        }
    }

    cout << dp[n-1];
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