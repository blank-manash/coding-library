#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) a.begin(),a.end()
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
bool left_dia[20] = {false};
bool right_dia[20] = {false};
bool row[10] = {false};

bool valid( int i, int j) {
    return ! ( left_dia[(i-j+n)] or right_dia[i+j] or row[j]);
}

void backtrack(vector<vi> &v, vi s, int i) {

    if( i > n-1) return;

    for(int j = 0; j < n; j++) {

        if ( valid(i,j))  {

            left_dia[(i-j+n)] = right_dia[i+j] = row[j] = 1;
            s.push_back(j);
            if( i == n-1) v.push_back(s);
            backtrack(v,s,i+1);
            s.pop_back();
            left_dia[(i-j+n)] = right_dia[i+j] = row[j] = 0;
        }
    }

}


void test() {

    cin >> n;
    vector<vi> res;
    memset(left_dia,false,sizeof(left_dia));
    memset(right_dia,false,sizeof(right_dia));
    memset(row,false,sizeof(false));
    vi v;
    backtrack(res,v,0);
    if( res.size() == 0) cout << -1;
    else {
        for( auto v : res ) {
            cout << "[";
            for ( int x : v ) cout << x+1 << " ";
            cout << "] ";
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