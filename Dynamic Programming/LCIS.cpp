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

    int n,m;
    cin >> n;
    cin >> m;
    vi x(n),y(m);
    input(x,n);input(y,m);
    vi dp(m,0);

    for( int i = 0; i < n; i++) {
        int curr = 0;
        for( int j = 0; j < m; j++) {

            if(x[i] > y[j]) curr = max(curr,dp[j]+1);
            if(x[i] == y[j]) dp[j] = max(dp[j],curr);
        }
    }

    cout << *max_element(a(dp));
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