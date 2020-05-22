#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

bool ispali( int n ) {
    vector<int> v;
    while( n > 0) {
        v.push_back(n%10);
        n/=10;
    }
    n = v.size();
    for(int i = n/2-1; i>=0; i--) {
        if(v[i] == v[n-1-i]) continue;
        return false;
    }

    return true;
}

const long long int MAX = 998001;
void test() {
    for( int i = MAX; i >=0; i--) {
        if(ispali(i)) {
            cout << i;
            return;
        }
    }
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCAL
freopen("input.txt","r",stdin);
#endif
    int T; cin >> T;
    T = 1;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}