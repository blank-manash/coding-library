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
    vi dp(n,1);
    int ans = 1;
    for( int i = 1; i < n; i++) {
        for( int j = 0; j < i; j++ ) {
            if( arr[j] < arr[i]) {

                dp[i] = max(dp[i],1+dp[j]);
                
            }
        }
        ans = max(ans,dp[i]);
    }
    
    cout << ans;
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