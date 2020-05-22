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

    string str;
    cin >> str;
    stack<char> s;

    for ( char ch : str ) {

        if( ch == '{' or ch == '(' or ch == '[') s.push(ch);
        else if ( ch == ')') {

            if ( s.empty() or s.top() != '(' ) {
                cout << "not balanced";
                return;
            }
            s.pop();
        }
        else if ( ch == '}') {

            if ( s.empty() or s.top() != '{') {
                cout << "not balanced";
                return;
            }
            s.pop();
        }
        else if ( ch == ']') {

            if ( s.empty() or s.top() != '[') {
                cout << "not balanced";
                return;
            }
            s.pop();
        }
    }
    if( !s.empty()) cout << "not balanced";
    else cout << "balanced";
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