#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

class Graph {

    vector<vi> adj;
    int V;
    Graph (int vertices) {
        V = vertices;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void Dijkstra();
    void BFS(int u) {

        vector<bool> visited(V,false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for( int v : adj[x]) {
                if(visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    void DFS(int u) {
        static vector<bool> visited(V,false);
        if(visited[u]) return;
        for( int v : adj[u]) {
            DFS(v);
            visited[v] = true;
        }
    }

};


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    


    return 0;

}