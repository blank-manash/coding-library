#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);

int pivot( vi arr, int s, int e) {

    if ( s > e ) return -1;
    if ( s == e) return s;
    int mid = (s+e) >> 1;

    if( mid-1 >= s and arr[mid] < arr[mid-1]) return mid;
    if( mid < e and arr[mid] > arr[mid+1]) return mid+1;
    if(arr[mid] < arr[e]) return pivot(arr,s,mid-1);
    else return pivot(arr,mid+1,e);

}


void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    cout << arr[pivot(arr,0,n-1)];

}


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif  //LOCAL
    int t;
    cin >> t;
    while(t--) {
        test();
        cout <<"\n";
    }
    return 0;

}

void input(vector<int> &v, int n) {

    for( int i =0; i<n ; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void input( int *arr, int n) {

    for ( int i =0; i < n; i++ ) cin >> arr[i];
}

void print(int *arr, int n) {

    for( int i = 0; i < n; i++) 
        cout << arr[i]<<" ";

    cout<<"\n";
}

void print(vector<int> &v) {

    for ( int x : v ) cout<<x<<" ";
    cout<<"\n";
}