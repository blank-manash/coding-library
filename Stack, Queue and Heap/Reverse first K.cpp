#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;


queue<ll> modifyQueue(queue<ll> q, int k)
{
    //add code here.
    queue<ll> qq;
    stack<ll> s;
    int n = q.size();
    while(q.size() != n-k) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        qq.push(s.top());
        s.pop();
    }
    while(!q.empty()) {
        qq.push(q.front());
        q.pop();
    }
    
    return qq;
    
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    


    return 0;

}