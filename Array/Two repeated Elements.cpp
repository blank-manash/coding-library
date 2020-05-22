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

pair<int,int> countfreq( vi arr) {

    int n = arr.size();
    pi p;
    for ( int i = 0; i<n; i++) {

        int index = arr[i]%n;
        arr[index] +=n; 
    }
    vi res;
    for(int i = 0; i < n; i++) arr[i] /=n;
    for (int i = 0; i < n; i++) if(arr[i] > 1) res.push_back(i);
    p.first = res[0];
    p.second = res[1];
    return p;
}


void test(){

    int n;
    cin >> n;
    vi arr;
    for ( int i = 0; i <n+2; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(--tmp);
    }

    pi p = countfreq(arr);
    cout << p.first+1 <<" "<< p.second+1;

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