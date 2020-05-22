#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

// ===================== MANASH =================== //
int ans,k;
struct trie {

    struct trie* kids[26];
    int cnt;
};

void insert ( trie *root,string s ) {
    
    trie *p = root;

    for( int i = 0; i < s.size(); i++) {

        int idx = s[i] - 'A';
        if(p->kids[idx] == NULL ) p->kids[idx] = new trie();
        p = p->kids[idx];
    }
    p->cnt++;
}

void dfs(trie *root, int level) {

    trie *p = root;
    for(int i = 0; i < 26; i++) {
        if( p->kids[i]) {
            dfs(p->kids[i],level+1);
            p->cnt += p->kids[i]->cnt;
        }
    }

    while(p->cnt >= k) {
        p->cnt -=k;
        ans+=level;
    }
}


void test() {

    int n;
    cin >> n >> k;
    ans = 0;
    trie *root = new trie();
    for( int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(root,s);
    }
    dfs(root,0);
    cout << ans;
    
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T; cin >> T;
    int i = 1;
    while(T--) {
        cout << "Case #" << i++ << ": ";
        test();
        cout << "\n";
    }
    return 0;

}