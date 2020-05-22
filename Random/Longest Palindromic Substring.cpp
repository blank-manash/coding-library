umap<pi,bool,hash_pair> ss;
int n;
int si,ei;
int maxlen;
void pali( string s, int i, int j) {

   if( i > j ) return;
    //if( i == j ) return 1;
    if( ss.find(mp(i,j)) != ss.end()) return;
    int mx = j-i+1;
    //left include, right include, both include, right shift.
    if ( i > 0 and s[i-1] == s[j] and mx == 1) {
        (pali(s,i-1,j));
    }
    if ( j+1 < n and s[i] == s[j+1] and mx == 1) {
        (pali(s,i,j+1));
    }

    if( j+1 < n and i > 0 and s[i-1] == s[j+1] ) {
       (pali(s,i-1,j+1));
    }
    if( maxlen < mx) {
        si = i;
        ei = j;
        maxlen = mx;
    }
    ss.insert(mp(mp(i,j),true));

    return;
}

void test(){

    string s;
    cin>>s;
    n = s.size();
    maxlen = 1;
    si = 0;
    ei = 0;
    ss.clear();
    for( int i = 0; i < s.size(); ++i) {
        pali(s,i,i);
    }
    cout<<s.substr(si,maxlen)<<"\n";
}