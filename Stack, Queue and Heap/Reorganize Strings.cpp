#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define dbl cout <<"--------------\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ====================== MANASH ======================== // 


void test() {

    string s;
    cin >> s;
    // Prev technique can be used when needed in alternating fashion.
    priority_queue<pair<int,char>> q;

    umap<char,int> m;
    for( char ch : s) {
        m[ch]++;
    }
    for(auto p : m) {
        q.push({p.second,p.first});
    }
    pair<int,char> prev = {-1,'#'};
    string ans;
    while(!q.empty()) {

        auto p = q.top(); q.pop();
        ans+=p.second;
        p.first--;
        if(prev.first > 0) q.push(prev);
        prev = p;
    }

    cout << ans;
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