#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define int long long
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n,m;
    cin >> m >> n;
    vi rows,columns;
    for(int i = 0; i < m-1; i++) {
        int t;
        cin >> t;
        columns.push_back(t);
    }
    for(int i = 0; i < n-1; i++ ) {
        int t;
        cin >> t;
        rows.push_back(t);
    }

    sort(a(rows),greater<int>());
    sort(a(columns),greater<int>());
    int cost = 0;
    int hori = 1, ver = 1;
    int i,j;
    for(i = 0, j = 0; i<rows.size() and j<columns.size(); ) {

        if(rows[i] > columns[j]) {

            cost += rows[i++]*ver;
            hori++;
        }

        else {

            cost += columns[j++]*hori;
            ver++;
            
        }
    }

    while( i < rows.size() ) {
        cost += rows[i++]*ver;
        hori++;
    }
    while( j < columns.size()) {
        cost += columns[j++]*hori;
        ver++;
    }

    cout << cost;
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