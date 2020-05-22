#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
int n;int m;
int dp[101][101];
const int inf = 1e5+7;

int edit_distance(string a, string b, int i, int j) {
    
    if( i > n-1 and j > m-1 ) return 0;
    if ( i == n or j == m) {
        int size1 = a.size() - i;
        int size2 = b.size() - j;
        return abs(size1-size2);
    }
    if( dp[i][j] != inf ) return dp[i][j];
    int x = inf;
    if( a[i] == b[j]) x = edit_distance(a,b,i+1,j+1);
    else {
        int insert = 1+edit_distance(a,b,i+1,j);
        int delet = 1+edit_distance(a,b,i,j+1);
        int replace = 1+edit_distance(a,b,i+1,j+1);

        x = min(x,min(insert,min(delet,replace)));
    }

    dp[i][j] = x;
    return x;

}


void test() {

    cin >> n >> m;
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 0; i < 101; i++) for ( int j = 0; j < 101; j++) dp[i][j] = inf;
    cout << edit_distance(s1,s2,0,0);
    
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