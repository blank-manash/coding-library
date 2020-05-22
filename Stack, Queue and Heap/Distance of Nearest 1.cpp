#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define inf 1000000007
#define deb(x) cout<< #x <<" == "<< x <<";\n"
#define fo(i,n) for(int i=0;i<n;i++)
#define forr(i,k,n) for(int i=k; k < n ? i<=n : i>=n ; k < n ? i++ : i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x,y) fo(i,sizeof(x)/sizeof(x[0]))x[i]=y
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define uset unordered_set
#define umap unordered_map
#define endl "\n"
#define all(v) v.begin(),v.end()
#define printf(x) cout<<x<<"\n"
#define sort(x) sort(all(x))
#define maxe(arr) *max_element(all(arr)) 
#define mine(arr) *min_element(all(arr))
#define sume(arr) accumulate(all(arr),0)

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);
void input( int *arr, int n);

struct hash_pair {

    template<class T1, class T2>

    size_t operator()(const pair<T1,T2> &p) const 
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        return hash1^hash2;
    }
};

/*-----------------------------MANASH ----------------------------------*/

int dir1[4] = {1,0,-1,0};
int dir2[4] = {0,1,0,-1};

bool isvalid( int i, int j, int n, int m) {
    return not (i<0 or j<0 or i>n-1 or j>m-1);
}


void bfs(vector<vi> &v, int n, int m) {

    vector<vi> dis(n,vi(m,-1));
    queue<pi> q;
    fo(i,n) fo (j,m) {
        
        if(v[i][j] == 1) {
            dis[i][j] = 0;
            q.push({i,j});
        }
    }
    while(!q.empty()) {
        pi c = q.front(); q.pop();
        int x = c.first;
        int y = c.second;

        for(int i = 0; i<4;i++) {
            int xx = x+dir1[i];
            int yy = y+dir2[i];

            if( not isvalid(xx,yy,n,m) or v[xx][yy] == 1 ) continue;
            dis[xx][yy] = (dis[x][y]+1);
            v[xx][yy] = 1;
            q.push({xx,yy});
        }
    }

    fo(i,n) fo(j,m) cout << dis[i][j] << " ";
    
}


void test() {
    
    int n; cin >> n;
    int m; cin >> m;
    //swap(n,m);
    vector<vi> v(n,vi(m,0));
    fo(i,n) fo(j,m) cin >> v[i][j];
    bfs(v,n,m);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif //LOCAL

    int T;
    cin>>T;
    while(T--)
    {
     	test();
        cout<<"\n";
    }

	return 0;
}













/*===================================== CODE =================================== */



void input(vector<int> &v, int n) {

    for( int i =0; i<n ; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void input( int *arr, int n) {

    for ( int i =0; i < n; i++ ) cin >> arr[i];
}

void print(int *arr, int n) {

    for( int i = 0; i < n; i++) 
        cout << arr[i]<<" ";

    cout<<"\n";
}

void print(vector<int> &v) {

    for ( int x : v ) cout<<x<<" ";
    cout<<"\n";
}