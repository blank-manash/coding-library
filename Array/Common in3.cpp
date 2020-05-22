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

void test() {

    // Find common elements in 3 array.
    // Using Bsearch in mlog(n)long(k) time,
    // or use set.
    int n,m,k;
    cin >> n >> m >> k;
    vi a,b,c; 
    input(a,n),input(b,m),input(c,k);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
       if(binary_search(a(b),a[i]) and binary_search(a(c),a[i]))
            s.insert(a[i]);
    }
    if ( not s.size()) cout << -1;
    else for(int x : s) cout << x <<" ";
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