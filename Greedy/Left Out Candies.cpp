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

    int n;
    cin >> n;
    int k;
    cin >> k;
    int tt = n*(n+1); tt/=2;
    while( k > tt ) k-=tt;
    for( int i = 1; i <= n; i++) {
        if( i > k ) {
            cout << k;
            return;
        }
        k-=i;
    }

    cout << 0;
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