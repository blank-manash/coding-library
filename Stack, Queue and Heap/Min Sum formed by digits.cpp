#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

// Alternating can mean jump.

int findSum(vi arr, int n) {

    int a = 0, b = 0;

    for(int i = 0; i<n; i++) {
        if(i&1) a = a*10 +arr[i];
        else b = b*10 +arr[i];
    }
    return a+b;
}



int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(),arr.end());
        cout << findSum(arr,n) << "\n";
    }    


    return 0;

}