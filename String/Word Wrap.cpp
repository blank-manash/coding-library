#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i];
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;

void wordwrap(vi arr, int n, int k) {

    vi ans(n+1,0),dp(n+1,inf);
    int curr = -1;
    dp[n-1] = 0;
    dp[n] = 0;
    ans[n-1] = n-1;
    for( int i = n-1; i >=0; i--) {

        curr = -1;
        for(int j = i; j < n; j++) {

            curr+= j == n-1 ? 0 : arr[j]+1;
            int cost = curr > k ? inf : (k-curr)*(k-curr) + dp[j+1];

            if( dp[i] > cost ) {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }

    for ( int i = 0; i < n; i = ans[i]+1) {
        cout << i+1 << " " << ans[i]+1 << " ";
    }
}


void test() {

    int n;
    cin >> n;
    vi arr(n);
    input(arr,n);
    int k; cin >> k;
    wordwrap(arr,n,k);
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