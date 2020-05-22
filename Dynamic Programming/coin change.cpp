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
    vi arr(n);
    input(arr,n);
    int c; cin >> c;
    int dp[n][c+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    for( int i = 0; i < n; i++) {
        for( int j = 0; j <=c; j++) {
            if( i == 0 ) {
                if( j >= arr[i] )dp[i][j] = dp[i][j-arr[i]];
                continue;
            }
            else if( j >= arr[i]) dp[i][j] += dp[i][j-arr[i]];
            dp[i][j] += dp[i-1][j];
        }
    }

    cout << dp[n-1][c];
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