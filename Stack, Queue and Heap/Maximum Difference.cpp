#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define dbl cout << "-----------\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ======================= MANASH ========================= //

int maxdiff( vi arr, int n) {

    stack<int> s;
    s.push(arr[0]);     // 2 1 7 6 8 
                        // st : 1 6 
    vi left(n,0); //
    for(int i = 1; i<n; i++) {
        int x = arr[i];
        while(!s.empty() and s.top() >= x) s.pop();
        if(!s.empty()) left[i] = s.top();
        s.push(x);
    }
    while(!s.empty()) s.pop();
    vi right(n,0);
    s.push(arr.back());
    for(int i = n-2; i>=0; i--) {

        int x = arr[i];
        while(!s.empty() and s.top() >= x) s.pop();
        if(!s.empty()) right[i] = s.top();
        s.push(x);
    }
    int ans = 0;
    for(int i = 0; i<n; i++) {
        ans = max(ans,abs(left[i]-right[i]));
    }

    return ans;

}


void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    cout << maxdiff(arr,n);

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