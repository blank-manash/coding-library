#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define int long long
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e9+7;
void test() {

    int n,k;
    cin >> n >> k;
    vi arr(n);
    input(arr,n);
    sort(a(arr));
    int mi = INT_MAX;
    for( int i = 0; i < n;i++) {
        if (arr[i] < 0 and k > 0) arr[i] = -arr[i], k--;
        mi = min(mi,arr[i]);
    }
    int sum = accumulate(a(arr),0);
    if(k&1) cout << sum-2*mi;
    else cout << sum;

    
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