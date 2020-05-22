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

void test() {
    int n;
    cin >> n;
    vector<vi> M(n,vi(n,0));

    for(int i = 0;i < n; i++) {
        for(int j = 0; j <n ; j++)
            cin >> M[i][j];
    }

    stack<int> s;
    for(int i = 0;i < n; i++) s.push(i);
    while(s.size() > 1) {
        int x1 = s.top();   s.pop();
        int x2 = s.top();   s.pop();
        if(M[x1][x2] == M[x2][x1]) continue;
        else if (M[x1][x2]) s.push(x2);
        else s.push(x1);
    }

    if (s.empty()) {
        cout << -1;
        return;
    }

    int cel = s.top();
    for( int i = 0; i < n; i++) {
        if(M[cel][i]) {
            cout << -1;
            return;
        }
    }
    cout << cel;
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