#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define int int64_t
#define umap unordered_map
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);

void multiply( vi &res, int x ) {

    int carry = 0;
    int n = res.size();
    for( int i = 0; i < n; i++) {

        int xx =res[i]*x + carry;
        res[i] = xx%10;
        carry = xx/10;
    }
    while(carry) {
        res.push_back(carry%10);
        carry /=10;
    }
}


void test() {

    int n;
    cin >> n;
    vi res;
    res.push_back(1);
    for( int i = 2; i <=n;i++) {
        multiply(res,i);
    }
    for( auto it = res.rbegin(); it != res.rend(); ++it) cout << *it;
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