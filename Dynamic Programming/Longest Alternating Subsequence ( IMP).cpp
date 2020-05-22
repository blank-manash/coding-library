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
    vi s(n);
    input(s,n);
    vi inc(n),dec(n);
    inc[0] = dec[0] = 1;
    for( int i = 1; i < n; i++) {

        if ( s[i] > s[i-1]) {
            inc[i] = dec[i-1]+1;
            dec[i] = dec[i-1];
        }
        
        else if ( s[i] < s[i-1] ) {
            inc[i] = inc[i-1];
            dec[i] = inc[i-1]+1;
        }
        else {
            inc[i] = inc[i-1];
            dec[i] = dec[i-1];
        }
    }

    cout << max(inc[n-1],dec[n-1]);
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