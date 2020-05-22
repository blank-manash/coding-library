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

bool twosum( vi arr, int s, int e, int k) {

    unordered_multiset<int> ss(arr.begin()+s,arr.begin()+e+1);
    for(int i = s; i <=e ; i++) {
        int x = arr[i];
        if ( x*2 == k and ss.count(x)>=2) {
            //d(x),d(x);
            return true;
        }
        else if ( x*2 != k and ss.find(k-x) != ss.end()){
            //d(x),d(k-x);
            return true;
    }
    
    }
    return false;
}

bool threesum(vi arr, int k) {

    int n = arr.size();
    for(int i = 0; i < n-2; i++) {
        int x = k - arr[i];
        if(twosum(arr,i+1,n-1,x)) {
            //d(arr[i]);
            return true;
        }
    }

    return false;
}
void test() {

    int n,k;
    cin >> n >> k;
    vi arr;
    input(arr,n);
    cout << threesum(arr,k);
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