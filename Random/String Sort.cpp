#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e6+7;
// ===================== MANASH =================== //
int n;



void test() {

    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char,int>> v;
    // If You want two types of sort, just pair them.
    for( int i = 0; i < (int)s.size(); i++) {
        v.push_back({s[i],i});
    }
    sort(v.rbegin(),v.rend());
    while(k--) v.pop_back();
    sort(a(v),[](pair<char,int> a, pair<char,int> b) {
        return a.second < b.second;
    });

    for( auto p : v ) cout << p.first;

}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T = 1;
    //int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

} 