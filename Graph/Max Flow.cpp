#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

int n,e;

bool bfs(vector<vi> &adj, int s, int t, vi &parent) {

    vector<bool> vis(n,false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {

        int u = q.front(); q.pop();
        for(int i = 0; i<n; i++) {
            if( not vis[i] and adj[u][i] > 0) {

                vis[i] = true;
                q.push(i);
                parent[i] = u;

            }
        }
    }
    return vis[t];
}

void test() {

    cin >> n >> e;
    vector<vi> adj(n,vi(n,0));
    for( int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        adj[a][b] += c;
        adj[b][a] += c;
    }
    int s = 0;
    int t = n-1;
    int max_flow = 0;
    vector<int> parent(n,-1);
    while(bfs(adj,s,t,parent)) {

        int path_flow = 1e5+7;
        for(int v = t; v != s; v = parent[v]) {
            path_flow = min(path_flow,adj[parent[v]][v]);
        }
        for(int v = t; v != s; v = parent[v]) {

            adj[parent[v]][v] -= path_flow;
            adj[v][parent[v]] += path_flow;
        }

        max_flow += path_flow;
    }

    cout << max_flow;
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