#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define int long long 
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

void test( int n) {

    vi arr(n);
    input(arr,n);
    int prev = arr[0];
    int cost = 0;
    for( int i = 1; i < n; i++) {

        int curr = arr[i];
        curr = curr+prev;
        cost += abs(prev);
        prev = curr;
    }

    cout << cost;
    
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    while(1) {
        int n;
        cin >> n;
        if(!n) break;
        test(n);
        cout << '\n';
    }
    return 0;

}