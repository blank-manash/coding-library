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

int minrev(string s) {

    if(s.size()&1) return -1;

    int left = 0, right = 0;
    int lc = 0,rc = 0;

    for( char ch : s) {
        if ( ch == '{') left++;
        else right++;
        if(right > left) {
            lc+= right -left;
            left = right = 0;
        }
    }
    left = right = 0;
    for(int i = s.size()-1; i>=0;i--) {
        if (s[i] == '}') right++;
        else left++;
        if(left > right) {
            rc+=abs(left-right);
            left = right = 0;
        }
    }
    rc = (rc&1) ? (rc/2)+1 : rc/2;
    lc = (lc&1) ? (lc/2)+1 : lc/2;

    return lc+rc;
}

void test() {

    string s;
    cin >> s;
    cout << minrev(s);

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