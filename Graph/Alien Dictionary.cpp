// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string printOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = printOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
// User function Template for C++
/*The function should return a string denoting the
order of the words in the Alien Dictionary */

void dfs( int u, vector<int> adj[], vector<bool> &vis, stack<int> &s) {

    if(vis[u]) return;
    vis[u] = true;
    for( int v : adj[u]) dfs(v,adj,vis,s);
    s.push(u);
}


string printOrder(string dict[], int N, int k) {
    // Your code here
   string ans;
   vector<int> adj[k];
   vector<vector<bool>> exist(k,vector<bool>(k,false));
   for(int i = 0; i<N-1; i++) {

        // Only need to check adjacent strings since dict is sorted.

           int itr = 0;
           string s1 = dict[i], s2 = dict[i+1];
           while((itr < s1.size() and itr < s2.size()) and s1[itr] == s2[itr]) itr++;
           if(not (itr < s1.size() and itr < s2.size())) continue;
           int ch1 = s1[itr] -'a';
           int ch2 = s2[itr] - 'a';
           if (exist[ch1][ch2] == false) adj[ch1].push_back(ch2),exist[ch1][ch2] = true;
       
   }
   vector<bool> vis(k,false);
   stack<int> s;
   for(int i = 0; i < k; i++) {
       if(not vis[i]) dfs(i,adj,vis,s);
   }
   int nn = s.size();
   while(nn--) {
       ans +=(s.top()+'a');
       s.pop();
   }

   return ans;
}