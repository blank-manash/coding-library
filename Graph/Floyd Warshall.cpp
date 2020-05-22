#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

const int INF = 1e7;

void test() {

    int V;
    cin >> V;
    int adj[V][V];
    int floyd[V][V];

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            int tmp;
            cin >> tmp;
            floyd[i][j] = adj[i][j] = tmp;
        }
    }

    for(int k = 0; k < V; k++) {
        for( int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }

    for(int i = 0; i < V; i++) {
        for( int j = 0; j<V; j++) {
            int value = floyd[i][j];
            if(value == INF) cout << "INF";
            else cout << value;
            cout << " ";
        }
        cout << "\n";
    }
    
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