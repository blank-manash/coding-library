// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */







ORDER OF STATEMENTS MATTER */


bool helper(int G[][MAX], int V, int src, int *color, bool *vis) {
    
     queue<int> q;
     vis[src] = true;
     color[src] = 0;
     q.push(src);
     
     while(!q.empty()) {
         int x = q.front();
         q.pop();
         for(int j = 0; j < V; ++j) {
             if(G[x][j])
             {
                 if(color[j] == color[x]) return false;
                 if(vis[j]) continue;
                 
                 q.push(j);
                 color[j] = 1 - color[x];
                 vis[j] = true;
             }
         }
     }
     
     return true;
}

bool isBipartite(int G[][MAX],int V)
{
     //Your code here
     bool vis[V];
     int color[V];
     memset(color,-1,sizeof(color));
     memset(vis,0,sizeof(vis));
     
     for( int i = 0; i < V; ++i ) {
         if(vis[i]) continue;
         //cout<<"for src : "<<i<<"  "<<helper(G,V,i,color,vis)<<endl;
         if( !helper(G,V,i,color,vis) ) return false;
     }  
    
    return true;
}