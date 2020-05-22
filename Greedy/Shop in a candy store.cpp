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
    sort(a(arr));
    int np = 0;
    for( int i = 0; n > 0; i++) {
        np+= arr[i];
        n-=k+1;
    }
    int xp = 0;
    n = arr.size();
    for ( int i = arr.size()-1; n > 0; i--) {
        xp+=arr[i];
        n-=k+1;
    }

    cout << np << " " << xp;

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