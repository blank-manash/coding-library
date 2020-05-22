#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;

int find_sma(string s, int c, int n) {

    int a[26];
    memset(a,0,sizeof(a));
    int min_len = inf;
    int start = 0;
    int count_dis = 0;
    for( int i = 0,j = 0; i <= j and j < n; ) {
        
        while( count_dis != c and j < n) {
            if(++a[s[j++]-'a'] == 1) count_dis++;
        }

        while( count_dis == c) {

            if(min_len > j-i) {

                start = i;
                min_len = j-i;
            }
            if(--a[s[i++]-'a'] == 0) count_dis--;

        }
    }

    return min_len;

}

void test() {

    string s;
    cin >> s;
    int a[26];
    memset(a,0,sizeof(a));
    for(char ch : s ) {
        a[ch-'a']++;
    }
    int c = count_if(a,a+26,[](int x) {
        return x != 0;
    });
    int n = s.size();
    cout << find_sma(s,c,n);

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