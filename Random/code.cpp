// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool dfs(int V, vector<int> adj[], bool *vis, bool*rstack, int i) {
    
    if( !vis[i] ) {
        
        vis[i] = true;
        rstack[i] = true;
        
        for(auto it : adj[i]) {
            
            int t = it;
            
            if(!vis[i] and dfs(V,adj, vis,rstack, t)) return true;
            else if(rstack[t]) return true;
        }
        
        rstack[i] = false;
    }
    
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V];
    bool rstack[V];
    memset(rstack,0,sizeof(rstack));
    memset(vis,0,sizeof(vis));
    for(int i = 0; i<V; i++) {
        if(vis[i]) continue;
        if(dfs(V,adj,vis,rstack,i)) return true;
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