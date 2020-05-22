#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ====================== MANASH ======================== // 
// 1 3 2 4
//  9 6 7 8

void my_approach( vi arr, int n) {
    umap<int,int> m;
    stack<int> s;
    int i = 0;
    for(;i<n;i++) {

        int x = arr[i];
        if(s.empty() or x <= s.top()) {

            s.push(x);
            continue;
        }
        else {

            while(!s.empty() and s.top() < x) {
                m[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }

    }
    for (int x : arr) {
            if(m.find(x) == m.end()) cout << -1 << " ";
            else cout << m[x] <<" ";
    }
}

void sol( vi arr, int n) {

    //iterate in reverse order,
    // find the element in stack.
    stack<int> s;
    for (int i = n-1; i > -1; i--) {
        int x = arr[i];
        while(!s.empty() and x > s.top()) s.pop();
        if (s.empty()) arr[i] = -1;
        else arr[i] = s.top();
        s.push(x);
    }
    print(arr);
}


void test() {
    
    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    sol(arr,n);
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
        //cout <<"\n";
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