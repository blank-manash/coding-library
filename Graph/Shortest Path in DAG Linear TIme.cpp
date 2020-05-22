#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

// Find Topological Order;

void dfs (int u, stack<int> &s, vector<int> adj[], vector<bool> &vis) {

    if(vis[u]) return;
    vis[u] = true;
    for( int v : adj[u]) dfs(v,s,adj,vis);
    s.push(u);
}
void shortestpath( int src, int V, vector<int> adj[]) {

    vector<bool> vis(V,false);
    stack<int> s;
    for(int i = 0; i < V; i++) dfs(i,s,adj,vis);
    // Now Stack Topo Sorted.
    vector<int> dis(V,INFINITY);
    int weight;
    dis[src] = 0;
    while(!s.empty()) {
        int u = s.top(); s.pop();
        if(dis[u] == INFINITY) continue;
        for( int v : adj[u])
            dis[v] = min(dis[v],dis[u]+ weight); // weight of the edge.
    }
    dis;
    return;

}

void test() {

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