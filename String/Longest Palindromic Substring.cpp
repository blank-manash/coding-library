#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    string s;
    cin >> s;
    int n = s.size();
    string ans;
    int maxlen = 1;
    int start = 0;
    for( int i = 0; i < n; i++) {

        // even length
        int high = i;
        int low = i-1;
        while(low >= 0 and high < n and s[low] == s[high]) {

            if( high-low+1 > maxlen) {
                start = low;
                maxlen = high-low+1;
            }
            high++;
            low--;
        }
        high = i;
        low = i;
        while(low >= 0 and high < n and s[low] == s[high]) {

            if( high-low+1 > maxlen) {
                start = low;
                maxlen = high-low+1;
            }
            high++;
            low--;
        }

    }

    cout << s.substr(start,maxlen);
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