#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}
typedef pair<int,int> pi;
int spanningTree(int V,int E,vector<vector<int> > graph)
{
    // code here
    unordered_set<int> spset;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    vector<int> key(V,INT_MAX);
    key[0] = 0;

    for(int i = 0; i < V; i++) {
        if(i == 0) q.push({0,0});
        else q.push({INT_MAX,i});
    }

    while(!q.empty()) {

        auto p = q.top(); q.pop();
        //cout <<"VALUE :  " << p.second << "; KEY == " << p.first << "\n";
        if(spset.find(p.second) != spset.end()) continue;
        int u = p.second;
        spset.insert(u);
        for(int j = 0; j<V; j++) {

            bool condition = graph[u][j] != INT_MAX and key[j] > graph[u][j];
            bool is_pre = spset.find(j) == spset.end(); // This is important because \
            if already present in the MST then key value doesn't matter.

            if(condition and is_pre){
                key[j] = graph[u][j];
                //cout << j << " ; KEY == " << key[j]<<"\n";
                q.push(make_pair(key[j],j));
            }
        }

    }
    return accumulate(key.begin(),key.end(),0);
}