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

    int n,k;
    cin >> n >> k;
    vi arr(n);
    input(arr,n);
    int best = 0, times = 0;
    for ( int x : arr ) {

        if (x > best) {

            best = x;
            times = 1;
        }
        else times++;
        if( times >= k ) {
            cout << best;
            return;
        }
    }

    cout << best; 
    return;
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