#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
int n,m;
int d1[4] = {1,-1,0,0};
int d2[4] = {0,0,1,-1};

void ffill(vector<vi> &arr,int i, int j, int prev, int nnew) {

    if ( i < 0 or j < 0 or i > n-1 or j > m-1 or arr[i][j] != prev) return;
    arr[i][j] =  nnew;
    for(int ii = 0; ii<4; ii++) {
        ffill(arr, i+d1[ii],j+d2[ii],prev,nnew);
    }
}

void test() {

    cin >> n >> m;
    vector<vi> arr(n,vi(m));
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin >> arr[i][j];


    int x,y, prev, nnew;
    cin >> x >> y >> nnew;
    prev = arr[x][y];
    ffill(arr,x,y,prev,nnew);

    //for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cout << arr[i][j] << " ";
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        //cout << "\n";
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