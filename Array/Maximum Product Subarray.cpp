#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);


int maxProduct(vector<int>& v) {

    int n = v.size();
    if ( n == 1 ) return v.back();
    int mni = 1, mxi = 1; bool zf = false, pf = false;
    int ans = 1;

    // Two Variables to find the max postive product and max negetive product.

    for( int x : v ) {
        
        int cmax = mxi;
        int cmin = mni;
        
        if( x == 0 ) mxi = 1, mni = 1, zf = true;
        else if ( x > 0 ) {
            mxi = cmax*x;
            mni = min(1,cmin*x);
            pf = true;
        }
        else {
            mxi = max(1,cmin*x);
            mni = cmax*x;
        }
        
        ans = max(ans,mxi);
    }
    
    if(zf and !pf and ans == 1) ans = 0; // V IMP CONDITION.
    return ans;
}


void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    cout << maxProduct(arr);
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