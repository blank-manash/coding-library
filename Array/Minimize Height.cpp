#include<bits/stdc++.h>
using namespace std;
#define db(x) cout << #x << " == " << x <<"\n"
#define uset unordered_set
#define umap unordered_map
#define a(x) x.begin(),x.end()
#define maxe(x) *max_element(a(x))
#define mine(x) *min_element(a(x))
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);


void test() {

    int n,k;
    cin >> k >> n;
    vi arr;
    input(arr,n);
    sort(a(arr));
    int ans = arr[n-1] - arr[0];
    int small = arr[n-1] - k;
    int big = arr[0] +k;
    if( small > big) swap(small,big);
    for( int i = 1; i<n-1; i++) {

        int add = arr[i] + k;
        int sub = arr[i] - k;
        // sub doesn't make it the smaller element or addition doesn'r make it \
        larger.
        if( sub >= small or add <= big) continue;

        // The Or statement exists because we don't want it to become the smallest or \
        largest respectively. That would increase = height.

        // Any Operation makes it the smallest and largest respectively

        else if (big - sub < add - small) small = sub;
        else big = add;
    }

    cout << min(ans,big-small);
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