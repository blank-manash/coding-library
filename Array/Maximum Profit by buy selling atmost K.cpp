#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define mp make_pair
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);


struct hash_pair {

    size_t operator()(const pi &p) const{
        auto hash1 = hash<int>{}(p.first);
        auto hash2 = hash<int>{}(p.second);

        return hash1^hash2;
    }
};

umap<pi,int,hash_pair> ss;

int mpak( vi arr, int i, int k) {
    // bought or ignored
    if ( k <= 0 or i < 0) return 0;
    if(ss.find(mp(i,k)) != ss.end()) return ss[mp(i,k)];
    
    int ig = mpak(arr,i-1,k);
    int sold = -1;
    for ( int j = 0; j < i; j++) {
        sold = max(sold,arr[i] - arr[j] + mpak(arr,j,k-1));
    }
    ss[mp(i,k)] = max(ig,sold);
    return ss[mp(i,k)];
}


void test() {

    int n,k;
    cin >> k >> n;
    vi arr;
    input(arr,n);
    ss.clear();
    cout << mpak(arr,n-1,k);
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