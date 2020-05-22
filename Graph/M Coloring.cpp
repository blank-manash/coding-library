#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

int n,m,e;

void test() {

    cin >> n;
    cin >> m >> e;
    vector<vector<int>> edges(n);
    int src = 0;
    for( int i = 0; i<e; i++) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        src = a;
    }
    vector<bool> vis(n,false);
    vector<int> color(n,-1);
    queue<int> q;
    int cnt = 1;
    q.push(src);
    vis[src] = true;
    color[src] = 1;
    while(!q.empty()) {

        int u = q.front(); q.pop();
        for(int v : edges[u]) {

            if(color[v] != -1 and color[v] != color[u]) continue;

            if(color[v] == -1) {
                if(color[u] == 1 ) color[v] = 2;
                else color[v] = color[u]-1;
                cnt = max(cnt,color[v]);
                q.push(v);
            }

            else if( color[v] == color[u]) {
                color[v] = color[u]+1;
                cnt = max(cnt,color[v]);
            }
        }
    }
    cnt > m ? cout << 0 : cout << 1;

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