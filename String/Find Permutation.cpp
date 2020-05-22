#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

// 1. Find the highest index `i` such that `s[i] < s[i+1]`. If no such index exists, the permutation is the last permutation.
// 2. Find the highest index `j > i` such that `s[j] > s[i]`. Such a `j` must exist, since `i+1` is such an index.
// 3. Swap `s[i]` with `s[j]`.
// 4. Reverse the order of all of the elements after index `i` till the last element.


void rev(vi &arr, int l, int r ) {

    while ( l < r ) swap(arr[l++],arr[r--]);
}

void test() {

    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0;i < n; i++) cin >> arr[i];
    int start = -1;
    for( int i = 0; i < n-1; i++) if ( arr[i] < arr[i+1] ) start = i;
    if( start == -1) {
        sort(arr.begin(),arr.end());
        for ( int x : arr ) cout << x << " ";
        return;
    }

    int end = start + 1;

    for(int j = start+1; j < n; j++) if( arr[j] > arr[start]) end = j;
    swap(arr[start],arr[end]);
    rev(arr,start+1,n-1);
    for ( int x : arr ) cout << x << " ";   

}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}