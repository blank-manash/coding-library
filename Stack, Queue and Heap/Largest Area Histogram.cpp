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

void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    stack<int> s;
    int maxarea = -1;
    int currarea = -1;

    // Store indices at stack 
    // -- COMMON MISTAKE -- //
    
    for(int i = 0; i<n; i++) {
        int x = arr[i];
        if (s.empty() or x >= /*This one -->*/arr[s.top()]) s.push(i);
        else {

            while(!s.empty() and x < arr[s.top()]) {
                int xx = s.top(); s.pop();
                //db(arr[xx-1]);
                currarea = s.empty() ? arr[xx]*(i) : arr[xx]*(i-s.top()-1); // i - s.top()\
                not xx;
                //db(currarea);
                maxarea = max(currarea,maxarea);
            }
            s.push(i);
        }
    }
    // Stack may not be empty now.

    while (!s.empty())
    {
        int xx = s.top(); s.pop();
        currarea = s.empty() ? arr[xx]*(n) : arr[xx]*(n-s.top()-1);
        maxarea = max(currarea,maxarea);
    }
    

    cout << maxarea;
    
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