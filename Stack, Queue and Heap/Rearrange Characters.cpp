#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

bool test() {
    
    // Worst Case Analysis.

    string s;
    cin >> s;
    umap<char,int> freq;
    for( char ch : s) {
        freq[ch]++;
    }
    int mx = 0;
    for( auto P : freq) {
        mx = max(mx,P.second);
    }
    int n = s.size();

    return n >=2*mx;

}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cout << test();
        cout << "\n";
    }


    return 0;

}