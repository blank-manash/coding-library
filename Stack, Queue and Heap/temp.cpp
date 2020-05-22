#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

bool canJump(vector<int>&arr) {

        int n = arr.size();
        if(n <= 1) return true;
        if(arr[0] == 0) return false;
        pair<int,int> interval {0,arr[0]};
        while(true) {
            int can_reach = -1;
            for(int i = interval.first; i <= interval.second; ++i) {
                can_reach = max(can_reach,i+arr[i]);
            }
            //cout << can_reach << "\n";
            if(can_reach>= n-1) return true;
            if( can_reach <= interval.second) return false;
            interval = {interval.second+1,can_reach};
        }
        
        assert(false);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    vi arr = {2,0};
    cout << canJump(arr) << "\n";

    return 0;

}