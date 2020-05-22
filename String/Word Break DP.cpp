#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;


uset<string> dict;

bool exist(string s) {

    if ( !s.size() ) return true;
    int k = 0;
    bool ans = false;
    for( k = 1; k <= s.size() ; k++) { // K characters.
        if(dict.find(s.substr(0,k)) != dict.end()) {
            ans = true;
            break;
        }
    }

    return ans and exist(s.substr(k));
}
void test() {

    int n; cin >> n;
    dict.clear();
    for(int i = 0; i<n; i++) {
        
        string s;
        cin >> s;
        dict.insert(s);
    }
    string s;
    cin >> s;
    cout << exist(s);
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