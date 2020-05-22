#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;

void heapify(vi &arr, int i ) {

    int n = arr.size();
    int id = i;
    int l = 2*i+1, r = 2*i+2;
    if( l < n and arr[l] < arr[id]) id = l;
    if( r < n and arr[r] < arr[id]) id = r;
    if(id == i) return;
    swap(arr[i],arr[id]);
    heapify(arr,id);
}

void buildheap(vi &arr) {

    int n = arr.size();

    for(int i = n/2-1; i>=0; i--)
        heapify(arr,i);
    
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    


    return 0;

}