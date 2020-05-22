#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);

class qstack { 
    private:
        queue<int> q1,q2;
    public:
        void push(int);
        void pop();
};
// q1 - 3
// q2 - 2 1
// 
void qstack :: push(int x) {

    q1.push(x);
    while(!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    swap(q1,q2);
}
void qstack :: pop() {

    if(q2.empty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << q2.front() << " ";
    q2.pop();
}

void test() {
    qstack q;
    q.push(1);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(6);
    q.pop();
}


int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif  //LOCAL
    int t;
    cin >> t;
    t = 1;
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