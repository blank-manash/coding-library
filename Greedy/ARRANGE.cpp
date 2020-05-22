#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define int long long 
#define double long double
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n;
    cin >> n;
    vi arr;
    int c1 = 0, c = 0;

    for( int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == 1) c1++;
        else c++,arr.push_back(t);
        
    }
    sort(a(arr));
    while(c1--) cout << 1 << " ";
    if( c == 2 and arr[0] == 2 and arr[1] == 3 ) {
        cout << "2 3";
        return;
    }
    for( int i = arr.size()-1; i >=0; i--) cout << arr[i] << ' ';
    
    
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