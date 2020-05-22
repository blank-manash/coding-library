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

int co( vi arr, int n, int k) {
    umap<int,int> m;
    vi res;
    for( int x : arr ) m[x]++;
    int ct = 0;
    for( pi p : m) {
        int xx = p.second;

        if( xx > n/k) res.push_back(p.first);
    }
    return res.size();
}


void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    int k; cin >> k;
    cout << (co(arr,n,k));
}


int main() {

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