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

    int w,h,n; 
    cin >> w >> h;
    cin >> n;
    
    vector<int> width,height;
    width.push_back(0),height.push_back(0);
    for(int i = 0; i < n; i++) {

        int a,b;
        cin >> a >> b;
        width.push_back(a);
        height.push_back(b);
    }
    width.push_back(w+1);
    height.push_back(h+1);
    sort(a(width)),sort(a(height));

    int max_width = 0, max_height = 0;

    for(int i = 0; i <=n; i++ ) {
        max_width = max(max_width,width[i+1] - width[i] - 1);
        max_height = max(max_height,height[i+1] - height[i] -1);
    }

    cout << max_height*max_width;
    
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