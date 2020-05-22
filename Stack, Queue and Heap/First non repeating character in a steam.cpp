#include<bits/stdc++.h>
using namespace std;
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {

    int n; cin >> n;
    queue<char> q;
    unordered_map<char,int> m;
    while(n--) {

        char ch;
        cin >> ch;
        m[ch]++;
        if(m[ch] == 1) q.push(ch);
        while(!q.empty() and m[q.front()] > 1) q.pop();
        if(q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
        

    }

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