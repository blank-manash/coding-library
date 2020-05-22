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



int lcs( vi arr, int n) {

    uset<int> ss;
    for ( int x : arr) ss.insert(x);
    int ans = 1;
    for( int i = 0; i < n; i++) {

        int x = arr[i];
        if( ss.find(x - 1) == ss.end()) {

            while(ss.find(x+1) != ss.end()) x++;
        }
        ans = max(ans,x-arr[i]+1);
    }

    return ans;
}


void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    cout << lcs(arr,n);
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