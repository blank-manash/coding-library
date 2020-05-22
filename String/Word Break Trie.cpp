#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;


struct Trie {

    bool is_end;
    struct Trie *kids[26];

    Trie() {
        is_end = false;
        for ( int i = 0; i < 26; i++) {
            kids[i] = NULL;
        }
    }
};

void insert( Trie* root, string s) {
    struct Trie *p = root;
    for( char ch : s) {
        int index = ch - 'a';
        if(!p->kids[index]) p->kids[index] = new Trie();
        p = p->kids[index];
    }
    p->is_end = true;
}

bool search( Trie* root, string s) {

    if(s.size() == 0) return true;
    Trie *p = root;
    for ( char ch : s ) {
        int i = ch-'a';
        if( p->kids[i] == NULL ) return false;
        p = p->kids[i];
    }

    return p and p->is_end;

}

bool search(string s,Trie *root) {
    if(s.size() == 0) return true;
    for(int i = 1; i <= s.size(); i++) {
        if(search(root,s.substr(0,i)) and search(s.substr(i),root)) return true;
    }
    return false;
}


void test() {

    int n; 
    cin >> n;
    Trie *root = new Trie();
    for( int i = 0; i<n; i++) {
        string s;
        cin >> s;
        insert(root,s);
    }

    string s;
    cin >> s;
    cout << search(s,root);

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