// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool dfs(int u, vector<int> adj[], vector<bool> &rstack, vector<bool> &vis) {
    
    if(vis[u]) return false;
    rstack[u] = true;
    vis[u] = true;

    for( int v : adj[u]) {
        if(vis[v] and rstack[v]) return true;
        if(not vis[v] and dfs(v,adj,rstack,vis)) return true;
    }
    rstack[u] = false;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> rstack(V,false);
    vector<bool> vis(V,false);
    for(int i = 0; i < V; i++) {
        if(vis[i]) continue;
        else if(dfs(i,adj,rstack,vis)) return true;
    }
    return false;

}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends