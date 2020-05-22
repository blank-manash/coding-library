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
    list<int> q;
    umap<int, list<int> :: iterator> m;
    vi arr(n);
    input(arr,n);
    int ans = 0;
    int k; cin >> k;
    for( int i = 0; i<n; i++) {

        int e = arr[i];
        if(q.size() < k) {

            if(m.find(e) == m.end()) ans++;
            else q.erase(m[e]);
            q.push_front(e);
            m[e] = q.begin();
        }
        else {
            if(m.find(e) == m.end()) {
                int last = q.back(); q.pop_back();
                m.erase(last);
                ans++;
            }
            else q.erase(m[e]);

            q.push_front(e);
            m[e] = q.begin();
        }
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