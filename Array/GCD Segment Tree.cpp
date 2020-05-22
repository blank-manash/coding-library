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


class Segment_Tree {

    private:
        int *tree;
        int *arr;
        int n;
    public:
        Segment_Tree(int *a, int size) {
            n = 4*size;
            tree = new int[n];
            arr = a;
            buildTree(tree,0,arr,0,size-1);
        }
        int l(int x) { return 2*x+1; }
        int r(int x) { return 2*x+2; }

        void buildTree(int *tree, int i, int *arr, int s, int e) {
            if( s > e) return;
            else if ( s == e ) tree[i] = arr[s];
            else {

                int mid = (s+e) >> 1;
                buildTree(tree,l(i),arr,s,mid);
                buildTree(tree,i,arr,mid,e);

                tree[i] = __gcd(tree[l(i)],tree[r(i)]);
            }
        }

        void updateRange( int *tree, int s, int e, int idx, int qe, int qs, int val) {

            if( qs > e or qe < s ) return;
            else if ( s >= qs and qe >= e) {
                tree[idx] = val;
                return;
            }
            else {

                int mid = (s+e)/2;
                updateRange(tree,s,mid,l(idx),qe,qs,val);
                updateRange(tree,mid,e,r(idx),qe,qs,val);
                tree[idx] = __gcd(tree[l(idx)],tree[r(idx)]);
            }

        }

        int query( int *tree, int s, int e, int idx, int qs, int qe) {
            if( qs > e or qe < s) return 0;
            if ( s >= qs and qe >= e) return tree[idx];
            else {

                int mid = (s+e) >> 1;
                int left = query(tree,s,mid,l(x),qs,qe);
                int right = query(tree,mid+1,e,r(x),qs,qe);

                return gcd(left,right);
            }
        }
}




void test() {

    int n;
    cin >> n;
    vi arr;
    input(arr,n);
    int k; cin >> k;
    cout << (co(arr,n,k));
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