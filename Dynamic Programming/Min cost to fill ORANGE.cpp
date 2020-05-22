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

    int n,w;
    cin >> n >> w;
    vi arr(n);
    for ( int i = 0; i < n; i++ ) {

        int tmp;
        cin >> tmp;
        if ( tmp == -1 ) tmp = inf;
        arr[i] = tmp;  
    }

    vector<vi> dp(n,vi(w+1,inf));

    for( int i = 1; i <= w; i++) dp[0][i] = i*arr[0];
    for( int j = 0; j < n; j++) dp[j][0] = 0;
    for( int i = 1; i < n; i++) {
        for( int j = 1; j <= w; j++) {
            
            int use_it = ( j-i-1>=0 ) ? arr[i] + dp[i][j-i-1] : inf ;
            int not_use_it = dp[i-1][j];

            dp[i][j] = min(use_it,not_use_it);
        }
    }

    dp[n-1][w] >=inf ? cout << -1 : cout << dp[n-1][w];
    
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