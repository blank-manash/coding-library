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


int game(vector<int> arr, int n) {

    int dp[n][n];
    memset(dp,0,sizeof(dp));

    for( int l = 2; l <= n; l++) {

        for( int i = 0; i < n; i++) {
            
            int j = l+i-1;
            if ( j > n-1 ) continue;
            if(l&1) dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
            else dp[i][j] = max(arr[i]+dp[i+1][j],arr[j]+dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}


void test() {

    int n;
    cin >> n;
    vector<int> arr;
    for( int i = 0; i < n; i++ ) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    cout << game(arr,n);
    
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