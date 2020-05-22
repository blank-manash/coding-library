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

void test() {

    vector<pi> v;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        pi p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(a(v),[](pi a, pi b) {
        return a.second > b.second;
    });

    stack<pair<int,int>> s;
    s.push(v[0]);

    for(int i = 1; i < n; i++) {

        pi c = v[i];
        pi p = s.top();
        if(p.first <= c.second) {
            int x1 = min(c.first,p.first);
            int x2 = max(c.second,p.second);
            pi pp = make_pair(x1,x2);
            s.pop();
            s.push(pp);
        }
        else s.push(c);
    }

    while(!s.empty()) cout << s.top().first << " " << s.top().second << " ", s.pop();

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