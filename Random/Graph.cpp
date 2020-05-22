#include<bits/stdc++.h>
using namespace std;

class Graph {
    
    int V;
    list <int> *adj;
    public:
        Graph ( int vertex ) {
            V = vertex;
            adj = new list<int>[V];
        }
        void addEdge( int u, int v) {

            adj[u].push_back(v);
        }
};
