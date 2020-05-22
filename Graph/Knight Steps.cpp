#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

int dir1[8] = {2,2,-1,1,-2,-2,1,-1};
int dir2[8] = {1,-1,2,2,1,-1,-2,-2};

bool valid (int x, int y, int n) {
    
    return not ( x < 0 or y < 0 or x > n-1 or y > n-1);
}

void test() {

    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    a--,b--,c--,d--;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    vector<vi> lvl(n,vi(n,0));
    queue<pair<int,int>> q;
    q.push({a,b});
    vis[a][b] = true;
    while(not q.empty()) {

        pi p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;

        for(int i = 0; i<8;i++) {
            int xx = x+dir1[i];
            int yy = y+dir2[i];

            if(not valid(xx,yy,n) or vis[xx][yy]) continue;
            lvl[xx][yy] = lvl[x][y]+1;
            if( xx == c and yy == d) {
                cout << lvl[xx][yy];
                return;
            }
            vis[xx][yy] = true;
            q.push({xx,yy});
        }
    }
    cout << 0;

}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef  LOCAL
    freopen("input.txt","r",stdin);
    #endif  //LOCAL

    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}