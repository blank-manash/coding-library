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

void test() {

    int n,m;
    cin >> n >> m;
    vi arr1,arr2;
    input(arr1,n);
    input(arr2,m);
    umap<int,int> s1,s2;
    for(int x : arr1) s1[x]++;
    for(int x : arr2) s2[x]++;

    for( int x : arr2) {
        if(s1.find(x) == s1.end() or s1[x] != s2[x]) {
            cout << "No";
            return;
        }

    }
    cout << "Yes";
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