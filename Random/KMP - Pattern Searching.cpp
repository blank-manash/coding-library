#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi findarray(string s) {

    int n = s.size();
    int i = 1, j = 0;
    vi arr(n,0);

    while(i < n) {
        if(s[i] == s[j]) arr[i++] = ++j;
        else {
            if ( j == 0)
                arr[i++] = 0;
            else j = arr[j-1];
        }
    }

    return arr;
}

int countp(vi str, vi text) {

    
    //cin >> txt;
    cin >> pat >> txt;
    vi arr = findarray(pat);
    int n = txt.size();
    int j = 0; int cnt = 0;
    int ishani = 0;

    while ( ishani < n ) {


        if (pat[j] == txt[ishani])
            ishani++,j++;
        
        if ( j == pat.size()) {
            cnt++;
            j = arr[j-1];
            continue;
        }

        if ( pat[j] != txt[ishani]) {
            if( j == 0 ) ishani++;
            else j = arr[j-1];
        }
    }
    
    return cnt;
}

int main() {
    cout << countp() << "\n";
}