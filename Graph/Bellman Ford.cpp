#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;

void test() {

    int V,E;
    cin >> V >> E;
    vector<pair<pi,int>> edges;
    vector<int> dis(V,inf);
    
    for(int i = 0; i < E; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({{u,v},w});
    }
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int w = edges[j].second;

            dis[v] = min(dis[v],dis[u]+w);
        }
    }

    for( int i = 0; i < E; i++) {

        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        if ( dis[v] > dis[u] + w ) {
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