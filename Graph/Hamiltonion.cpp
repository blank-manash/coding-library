#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

int V,e;
bool bactrack(vector<int> adj[], vector<bool> &vis, int u, int cnt) {


    if(cnt == V) return true;
    if(vis[u]) return false;
    vis[u] = true;
    for( int v : adj[u]) {
        if(vis[v]) continue;
        if(bactrack(adj,vis,v,cnt+1)) return true;
    }
    vis[u] = false;
    return false;
}

void test() {

    cin >> V;
    cin >> e;
    vector<int> adj[V];
    int src = 0;
    for(int i = 0; i<e; i++) {

        int a,b;
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        src = a;
    }
    vector<bool> vis(V,false);
    
    for(int i = 0; i<V;  i++) {
        if(bactrack(adj,vis,i,1)){
            cout << 1;
            return;
        }
    }

    cout << 0;

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