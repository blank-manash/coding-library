#include<bits/stdc++.h>
using namespace std;
#define db(x) cout << #x << " == " << x <<"\n"
#define uset unordered_set
#define int long long int
#define umap unordered_map
#define a(x) x.begin(),x.end()
#define maxe(x) *max_element(a(x))
#define mine(x) *min_element(a(x))
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);

const int inf = INT_MAX-2;

umap<int,int> m;
// Recursive
int mj( vi arr, int i) {

    if ( i == 0) return 0;
    if (( i!= arr.size()-1 and arr[i] == 0) or i < 0 ) return inf;
    if (m.find(i) != m.end()) return m[i];
    int ans = inf;

    for ( int j = i-1; j >=0; j--) {
        if( arr[j] >= i-j) ans = min(ans,1+mj(arr,j));
    }
    m.insert(make_pair(i,ans));
    return ans;
}

// Iterative

int mj( vi arr) {

    int n = arr.size();
    vi dp(n,inf);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for( int j = i-1; j >=0; j--) {
            if(arr[j] >= i-j) dp[i] = min(dp[i],1+dp[j]);
        }
    }
    return dp[n-1];
}

void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    int ans = mj(arr);
    if ( ans >=inf) cout << -1;
    else cout << ans;
    
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