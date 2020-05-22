#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

void test() {
    vi arr;
    int n; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int k; cin >> k;
    queue<int> q;
    int i = 0;
    while(q.size() != k ) q.push(arr[i++]);
    for(i = k; i <= n; i++) {
        
        while(q.size() != 0 and q.front() > 0 ) q.pop();
        if(q.empty()) cout << 0 << " ";
        else cout << q.front() << " ";
        if( i < n ) q.push(arr[i]);
        if(q.size() > k) q.pop(); 
    }


}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // DEBUG

    int t;
    cin >> t;
    while(t--) {
        test();
        cout << "\n";
    }
    


    return 0;
}
