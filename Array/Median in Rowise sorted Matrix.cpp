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


int partition( vi &arr, int s, int e) {

    assert( s <= e);    
    int piv = arr[e];
    int i = s;
    for( int j = s; j<e; j++)
        if(arr[j] < arr[e]) 
            swap(arr[j],arr[i++]);

    swap(arr[i],arr[e]);
    return i;
}

int quickselect( vi &arr, int s, int e, int k) {

    if ( s > e ) return -1;
    int pos = partition(arr,s,e);
    int mid = pos;
    if ( pos == k ) return arr[pos];
    if ( pos > k ) return quickselect(arr,s,mid-1,k);
    else return quickselect(arr,mid+1,e,k);
}

int findMedian ( vi &arr) {
    int n = arr.size();
    return quickselect(arr,0,n-1,n/2);
}

void test() {

    int n,m;
    cin >> n >> m;
    vi v;
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
    }
    //print(v);
    cout << findMedian(v);
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

void print(vector<int> &v) {

    for ( int x : v ) cout<<x<<" ";
    cout<<"\n";
}