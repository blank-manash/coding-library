#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define dbl cout << "-----------\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ======================= MANASH ========================= //

void sortedInsert(stack<int> &s, int e) {

    if ( s.empty() or s.top() > e) s.push(e);
    else {
        int tmp = s.top(); s.pop();
        sortedInsert(s,e);
        s.push(tmp);
    }
}

void sortstack(stack<int> &s) {

    if(s.empty() or s.size() == 1) return;
    int x = s.top(); s.pop();
    sortstack(s);
    sortedInsert(s,x);
}


void test() {
    stack<int> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        s.push(tmp);
    }
    for(int i = 0; i < n; i++) {
        sortstack(s);
    }
    while(!s.empty()) cout << s.top() << " ", s.pop();
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif  //LOCAL
    int t;
    cin >> t;
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