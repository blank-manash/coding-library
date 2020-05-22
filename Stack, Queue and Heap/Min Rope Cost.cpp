#include<bits/stdc++.h>
using namespace std;

#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define dbl cout <<"--------------\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ====================== MANASH ======================== // 



void test() {
    
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    
    for(int i = 0; i<n; i++) {
        int t;
        cin >> t;
        q.push(t);
    }
    int cost = 0;
    while(q.size() > 1) {

        int t1 = q.top(); q.pop();
        int t2 = q.top(); q.pop();
        cost += t1+t2;
        q.push(t1+t2);
    }
    
    cout << cost;
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