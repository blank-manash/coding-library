#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n,m;
    cin >> n >> m;
    int wall; cin >> wall;
    int ans_m,ans_b, min_empty = 0;
    int p = 0,q = 0,rem; // TRY OUT ALL POSSIBLE COMBINATIONS AND SELECT MINI.
    while ( wall >= n ) {
        p = wall/m;
        rem = wall%m;
        if( rem < min_empty) {
            ans_m = p;
            ans_m = q;
        }
        q++;
        wall-=n;
    }
    cout << ans_m << " " << ans_b << "\n";
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