#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool endOfword;
    struct Trie* kids[26];

    Trie() {
        endOfword = false;
        for( int i = 0; i < 26; i++)
            kids[i] = NULL;
    }
};

void insert(Trie* root,string key) {

    Trie* pcrawl = root;
    for(int i = 0; i<key.size();i++) {
        
        int idx = key[i] - 'a';
        if( pcrawl->kids[idx] == NULL)
            pcrawl->kids[idx] = new Trie();

        pcrawl = pcrawl->kids[idx];
        
    }
    pcrawl->endOfword = true;
}

bool search(Trie *root, string key) {

    Trie* pc = root;
    for ( char ch : key) {
        int idx = ch - 'a';
        if( pc->kids[idx] == NULL) return false;
        pc = pc->kids[idx];
    }
    return (pc and pc->endOfword);
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    struct Trie* root = new Trie();
    string keys[] = {"manash","why","blackandwhite","insanity"};
    int n = 4;
    for( int i = 0; i< 4; i++)
        insert(root,keys[i]);

    bool sear = search(root,"no");
    cout<<sear<<"\n\n";    
    
    return 0;
}
