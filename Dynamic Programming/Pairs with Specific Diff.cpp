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
    int k; cin >> k;
    sort(a(arr));
    int sum = 0;
    for( int i = n-1; i>0; ) {
        
        int curr = arr[i];
        int prev = arr[i-1];
        if (abs(curr-prev) < k ) {
            sum+= curr+prev;
            i-=2;
        }
        else i-=1;
    }

    cout << sum;
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