#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ======================= MANASH ========================= //
stack<int> s;
    
void recursion( int x ) {
// Takes each element and puts it into the first place
    if(s.empty()) s.push(x);
    else {
        int y = s.top();    s.pop();
        recursion(x);
        s.push(y);
    }
}
void reverse() {
// Reverses a stack, take each element and puts it in top;
    if(s.empty()) return;
    int y = s.top(); s.pop();
    reverse();
    recursion(y);
}

void test() {
    int n = 3;
    while(n--) s.push(n);
    reverse();
    while(!s.empty()) cout << s.top() <<" ", s.pop();
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif  //LOCAL
    int t;
    cin >> t;
    t = 1;
    while(t--) {
        test();
        cout <<"\n";
    }
    return 0;

}

void input(vector<int> &v, int n) {

    for( int i =0; i<n ; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void print(vector<int> &v) {

    for ( int x : v ) cout<<x<<" ";
    cout<<"\n";
}