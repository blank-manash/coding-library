#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

// ===================== MANASH =================== //

int dp[1501][1501];
int n,m;
int find_beauty(vector<vi> arr, int p ) {

    int ans = 0;
    int cost = 0;

    for ( int i = n-1; i >=0; i-- ) {// PARAMETERS;

        for ( int plate = 0; plate <=p; plate++) { // Two States of DP;
            
            // INSIDE THE RECURSIVE FUNCTION.
            int cost = 0;
            int inc = 0;
            for(int j = 0; j < m; j++) {
                
                if( inc < plate ) {
                    cost+= arr[i][j];
                    inc++;
                    dp[i][plate] = max(dp[i][plate],cost+dp[i+1][plate-inc]);
                }
            }
            dp[i][plate] = max(dp[i][plate],dp[i+1][plate]);
        }
    }

    return dp[0][p];
}
void test() {
    

    cin >> n >> m;
    int p;
    cin >> p;
    vector<vi> plates(n,vi(m));
    for(int i = 0; i < n; i++) {
        for( int j = 0; j < m; j++) {

            cin >> plates[i][j];
        }
    }
    memset(dp,0,sizeof(dp));

    cout << find_beauty(plates,p);
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T; cin >> T;
    int i = 1;
    while(T--) {
        cout << "Case #" << i++ << ": ";
        test();
        cout << "\n";
    }
    return 0;

}