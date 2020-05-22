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

    int n,i,d,c;
    cin >> n;
    cin >> i >> d >> c;
    int dp[n+1];
    for ( int i = 0; i < n+2; i++ ) dp[i] = inf;
    dp[0] = inf;
    dp[1] = i;
    dp[2] = min(i+dp[1],c+dp[1]);
    for ( int j = 3; j <= n; j++) {

        if (j&1) dp[j] = min(dp[j-1]+i,c+d+dp[(j+1)/2]);
        else dp[j] = min(dp[j-1]+i,c+dp[(j/2)]);
    }

    cout << dp[n];
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    
    //dp[0] = 0;
    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}