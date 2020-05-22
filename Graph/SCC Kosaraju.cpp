// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/


void dfs ( stack<int> &s, int u, vector<int> adj[], vector<bool> &vis) {

    if(vis[u]) return;
    vis[u] = true;
    
    for(int v : adj[u]) dfs(s,v,adj,vis);
    s.push(u);
    // This ordering is very important.
}

void dfs(int u,vector<int> adj[],vector<bool> &vis) {
        //cout << "v is :  " << v << "\n";
    if(vis[u]) return;
    vis[u] = true;
    //s.push(u);
    for(int v : adj[u]) dfs(v,adj,vis);
}

int kosaraju(int V, vector<int> adj[])
{
    int cnt = 0;
    stack<int> s;
    vector<bool> vis(V,false);
    for(int i = 0; i < V; i++) dfs(s,i,adj,vis);

    vector<int> radj[V];
    for(int i = 0; i < V; i++) {
        for( int v : adj[i]) {
            radj[v].push_back(i);
        }
    }

    fill(vis.begin(),vis.end(),false);

    while(!s.empty()) {

        int v = s.top();    s.pop();
        if(vis[v]) continue;
        dfs(v,radj,vis);
        cnt++;
    }

    return cnt;

}

// { Driver Code Starts.

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}  // } Driver Code Ends