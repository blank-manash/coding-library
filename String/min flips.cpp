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

    string s;
    cin>> s;
    string a,b;
    for( int i = 0; i < s.size(); i++) {

        if( i&1 ) {
            a+='1';
            b+='0';
        }
        else {
            a+='0';
            b+='1';
        }
    }

    int c1 = 0, c2 = 0;

    for(int i = 0; s[i]; i++) {
        
        char c = s[i];
        if (c != a[i]) c1++;
        if( c!= b[i] ) c2++;
    }

    cout << min(c1,c2);
    
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