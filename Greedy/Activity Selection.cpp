#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

struct event {

    int start;
    int end;
    int id;
};


void test() {

    int n;
    cin >> n;
    event e[n];
    for( int i = 0; i < n; i++) {
        cin >> e[i].start;
        e[i].id = i+1;
    }
    for( int i = 0; i < n; i++) {
        cin >> e[i].end;
    }
    sort(e,e+n,[](event e1, event e2) {
        return e1.end < e2.end;
    });
    event prev  = e[0];
    cout << prev.id << " ";
    for( int i = 1; i < n; i++) {
        event curr = e[i];
        if( curr.start < prev.end ) continue;
        cout << curr.id << " ";
        prev = curr;
    }
    
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