#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define d(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);


int fi( vi arr, int s, int e ) {

    //d(s),d(e);

    if( s > e ) return -1;
    if ( s == e and arr[s] == 1) return s;
    int mid = (s+e) >> 1;
    if ( arr[mid] == 1 and mid > s and arr[mid-1] == 0) return mid;
    if ( arr[mid] == 1 and mid == s ) return s;
    if ( arr[mid] == 0 and mid < e and arr[mid+1] == 1) return mid+1;
    if ( arr[mid] == 1) return fi(arr,s,mid-1);
    else return fi(arr,mid+1,e);

}

int fr( vector<vi> v, int n, int m) {
    int mx = INT_MAX, ans = 0;

    for( int i = 0; i<n; i++) 
    {

        int index = fi(v[i],0,m-1);
        if( index != -1 and mx > index) {
            mx = index;
            ans = i;
        }
    }
    return ans;
}

void test() {

    int n,m;
    cin >> n >> m;
    vector<vi> v(n,vi(m,0));
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++) cin >> v[i][j];
    }
    cout << fr(v,n,m);
}


int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif  //LOCAL
    int t;
    cin >> t;
    while(t--) {
        test();
        cout <<"\n";
    }
    return 0;

}

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