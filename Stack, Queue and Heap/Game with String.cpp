#include<bits/stdc++.h>
using namespace std;
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    string s;
    cin >> s;
    //sort(s.begin(),s.end());
    //cout << s;
    int n = s.size();
    int k; cin >> k;
    unordered_map<char,int> m;
    for( char ch : s) m[ch]++;
    priority_queue<int> q;
    for( auto p : m) q.push(p.second);
    for(int i = 0; i < k; i++) {
        int tp = q.top(); q.pop();
        q.push(--tp);
    }

    int sum = 0;
    while(!q.empty()) sum+=q.top(),q.pop();
    cout << sum;

}


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    while(t--) {
        test();
        cout << "\n";
    }


    return 0;

}