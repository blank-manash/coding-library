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
    int n,k;
    cin >> n >> k;
    umap<int,int> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    priority_queue<pair<int,int>> q;
    for(auto p : m) {
        q.push({p.second,p.first});
    }
    while(k--) {
        auto p = q.top(); q.pop();
        int ele = p.second;
        if(m[ele] != 0) m[ele]--;
        q.push({m[ele],ele});
    }
    int distinct = 0;
    for(auto p: m) {
        if(p.second) distinct++;
    }
    cout << distinct;
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