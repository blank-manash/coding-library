#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n;
    cin >> n;
    vi arr(n),dep(n);
    input(arr,n);
    input(dep,n);
    int ans = 1;
    int station = 1;
    sort(a(arr));
    sort(a(dep));
    for (int i = 1, j = 0; i < n and j < n; ) {

        if( dep[j] >= arr[i] ) station++,i++;
        else station--,j++;
        ans = max(ans,station);
    }

    cout << ans;
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