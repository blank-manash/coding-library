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
    int dp[3][n+1];
    int arr[3] = {3,5,10};
    memset(dp,0,sizeof(dp));
    for( int i = 0; i <=n; i+=3 ) dp[0][i] = 1;
    dp[1][0] = dp[2][0] = 1; // INPORTANT STEP.
    for( int i = 1; i < 3; i++) {

        for( int j = 1; j <= n; j++) {

            dp[i][j] += dp[i-1][j]; // NO ONE ADDED.
            if( j>= arr[i] ) dp[i][j] += dp[i][j-arr[i]];
        }
    }

    // for( int i = 0 ; i < 3; i++ ) {
    //     for( int j = 0; j <=n; j++) cout << dp[i][j] << " ";

    //     cout << "\n";
    // }

    cout << dp[2][n];
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