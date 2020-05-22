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

int high,low;

bool valid(vi arr, int n, int k, int ans) {

    int painters = 1;
    int curr_sum = 0;

    for( int i = 0; i < n; i++) {
        
        if ( curr_sum + arr[i] > ans ) {
            curr_sum = arr[i];
            painters++;
            if (painters > k ) return false;
        }
        else curr_sum+=arr[i];
    }

    return true;
}

void test() {

    int n,k;
    cin >> k >> n;
    vi arr(n);
    input(arr,n);
    high = accumulate(a(arr),0);
    low = *max_element(a(arr));
    int ans = inf;
    while( high >= low ) {

        int mid = (high+low) >> 1;
        if (valid(arr,n,k,mid)) {
            high = mid-1;
            ans = min(ans,mid);
        }
        else low = mid+1;
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