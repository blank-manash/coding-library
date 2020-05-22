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

void test() {

    int n,d;
    cin >> n; // REVERSE !!!!!!!!
    cin >> d;
    vi arr(n);
    input(arr,n);
    int prev = d;

    for( int i = n-1; i >=0; i--) {
        int curr = arr[i];
        curr = prev - prev%curr;
        prev = curr;
    }

    cout << prev;
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T; cin >> T; int i = 1;
    while(T--) {
        cout << "Case #" << i++ << ": ";
        test();
        cout << "\n";
    }
    return 0;

}