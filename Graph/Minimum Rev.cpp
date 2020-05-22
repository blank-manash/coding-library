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
    int src,dest;
    cin >> src >> dest;
    vector<pair<int,int>> adj[V];
    for(int i = 0; i <E; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back({b,0});
        adj[b].push_back({a,1}); // KEY POINT. MIN DIS WHEN REVERSAL \
        COSTS 1.
        // Can be applied to many concepts.
    }

    vector<int> dis(V,inf);
    set<pi> s;
    s.insert({0,src});
    while(!s.empty()) {

        pi p = *s.begin();
        s.erase(s.begin());
        int u = p.second;
        for( pi pp : adj[u]) {

            int v = pp.second;
            int w = pp.first;
            if( dis[v] > dis[u]+w) {
                if(dis[v] != inf) {
                    s.erase(s.find({dis[v],v}));
                }
                dis[v] = dis[u]+w;
                s.insert({dis[v],v});
            }
        }
    }

    cout << dis[dest];
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