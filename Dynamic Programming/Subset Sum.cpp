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
int n,total;

void test() {

    cin >> n;
    vi arr(n);
    input(arr,n);
    int sum = accumulate(a(arr),0);
    if( sum&1 ) {
        cout << "NO";
        return;
    }
    total = sum/2;
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));

    //dp[i][currsum] = dp[i-1][currsum] or dp[i][cuursum-arr[i]];
    for( int i = 0; i <= n; i++) {
        for( int s = 0; s <= total; s++) {

            if( s == 0 ) dp[i][s] = true;
            else if ( i == 0 ) dp[i][s] = false;
            else if ( arr[i] > s ) dp[i][s] = dp[i-1][s];
            else dp[i][s] = dp[i-1][s] or dp[i-1][s-arr[i]];
        }
    }
    
    dp[n][total] ? cout << "YES" : cout << "NO";

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