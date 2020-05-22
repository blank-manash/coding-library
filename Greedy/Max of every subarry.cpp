#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

class Queue {
    queue<int> q;
    multiset<int,greater<int>> s;
    public:
        void push(int x) {
            q.push(x);
            s.insert(x);
        }
        int getMax() {

            if(!s.empty()) return *s.begin();
            else return -1;
        }
        void pop() {

            if(q.empty()) return;
            int x = q.front(); q.pop();
            auto it = s.lower_bound(x);
            // ERASE A SINGLE ELEMENT.
            s.erase(it);
        }
};

void test() {

    int n; cin >> n;
    int k; cin >> k;
    Queue q;
    for(int i = 0; i<n; i++) {
        int t;
        cin >> t;
        q.push(t);

        if( i >= k-1 ){
            cout << q.getMax() << " ";
            q.pop();
        }
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