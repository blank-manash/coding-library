#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int findpiv (vi arr, int s, int e) {

    if( s > e ) return -1;
    if ( s == e ) return e;
    int mid = (s+e)/2;

    if ( mid < e and arr[mid+1] < arr[mid]) return mid+1;
    if ( mid > s and arr[mid-1] > arr[mid]) return mid;
    else if ( arr[e] > arr[mid]) return findpiv(arr,s,mid-1);
    else return findpiv(arr,mid+1,e); 
}

int bsearch( vi arr, int s, int e, int k) {
    if ( s > e ) return -1;
    int mid = (s+e)/2;
    if ( arr[mid] == k ) return mid;
    if ( arr[mid] > k ) return bsearch(arr,s,mid-1,k);
    return bsearch(arr,mid+1,e,k);
}

int rsearch( vi arr, int k) {
    int n = arr.size();
    int piv = find(piv,0,n-1);
    if ( piv == -1 ) return bsearch(arr,0,n-1,k);
    if(arr.back() >= arr[piv] ) return bsearch(arr,piv+1,n-1,k);
    else return bsearch(arr,piv+1,n-1,k);
}



int main() {

}