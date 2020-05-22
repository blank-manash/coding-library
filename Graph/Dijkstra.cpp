#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 10000007;
typedef pair<int,int> pi;
// =========== PRIORITY QUEUE IMPLEMENTATION ============= //

typedef pair<int,int> pi;
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    priority_queue<pi,vector<pi>,greater<pi>> q;
    vector<int> dis(V,INT_MAX-1000);
    q.push({0,src});
    dis[src] = 0;
    
    while(!q.empty()) {
        
        int u = q.top().second; q.pop();
        
        for(int i = 0; i < V; i++) {
            if(graph[u][i] == 0) continue;
            if(dis[i] > dis[u]+graph[u][i]) {
                dis[i] = dis[u]+graph[u][i];
                q.push({dis[i],i});
            }
        }
    }
    
    for(int i = 0; i < V; i++) cout << dis[i] << " ";
}

// =================== SET ======================= //
void Djikstra( int src, vector<vector<pair<int,int>>> &adj) {

    int V = adj.size();
    set<pair<int,int>> spset;
    // We can also use Priority queue.
    spset.insert({0,src});
    vector<int> dis(V,inf);
    dis[src] = 0;

    while(!spset.empty()) {
        
        pi p = *(spset.begin());
        int u = p.second;
        spset.erase(spset.begin());

        for( pi v : adj[u]) {
            int vv = v.second;
            int w = v.first;
            if( dis[vv] > dis[u] + w) {
                if(dis[vv] != inf) spset.erase(spset.find({dis[vv],vv}));
                dis[vv] = dis[u] + w;
                pi pp = make_pair(dis[vv],vv);
                spset.insert(pp);
            }
        }
    }
}

void test() {
    
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}