#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    vector<int> move(30,-1);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        move[a] = b;
    }

    vi lvl(30,0);
    vector<bool> vis(30,false);
    lvl[0] = 0;
    vis[0] = true;
    queue<int> q;
    q.push(0);

    while(!q.empty()) {

        int u = q.front(); q.pop();

        for(int i = u+1; i <= u+6; i++) {

            int v = i;
            if( move[v] != -1 ) v = move[v];
            // Excellent Key Point.
            if(vis[v] == true) continue;
            lvl[v] = lvl[u]+1;
            vis[v] = true;
            q.push(v);

            if( v == 29 ) {
                cout << lvl[v];
                return;
            }
        }
    }

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