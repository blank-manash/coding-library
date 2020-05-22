// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void dfs(int u,stack<int> &s, vector<int> adj[],vector<bool> &vis) {
    
    if(vis[u]) return;
    vis[u] = true;
    for( int v : adj[u]) {
        dfs(v,s,adj,vis);
    }
    s.push(u); // Trick to insert at first.
}

int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    stack<int> s;
    vector<bool> vis(V,false);
    
    for(int i = 0; i < V; i++) {
        dfs(i,s,adj,vis);
    }
    int n = s.size();
    int *arr =new int[n];
    
    for(int i = 0; i<n; i++) {
        arr[i] = s.top(); s.pop();
    }
    
    return arr;
}


// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]) {
    bool flag = true;
    for (int i = 0; i < V && flag; i++) {
        int n = adj[res[i]].size();
        for (auto j : adj[res[i]]) {
            for (int k = i + 1; k < V; k++) {
                if (res[k] == j) n--;
            }
        }
        if (n != 0) flag = false;
    }
    if (flag == false) return 0;
    return 1;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int* res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}
  // } Driver Code Ends