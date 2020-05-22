#include <bits/stdc++.h>
#define printf(x) cout<<x<<"\n"
using namespace std;

class SegmentTree {
    private:
        int *tree;
        int *arr;
        int (*op)( int, int );
        int n;
        int l ( int i ) { return 2*i+1; }
        int r ( int i ) { return 2*i+2; }  
        void buildTree ( int *tree, int *arr, int i, int s, int e) {

            if ( s>e) return;
            else if( s == e) tree[i] = arr[s];
            else 
            {
                int mid = (s+e)/2;
                buildTree(tree,arr,l(i),s,mid);
                buildTree(tree,arr,r(i),mid+1,e);
                tree[i] = op(tree[l(i)], tree[r(i)]);
            }
        }

        int queryUtil(int *tree, int *arr, int i, int s, int e, int qs, int qe) {

            if ( qe < s or qs > e ) return 0;
            if ( s>=qs and qe >=e ) return tree[i];
    
            int mid = (s+e)/2;
            int left = queryUtil(tree,arr,l(i),s,mid,qs,qe);
            int right = queryUtil(tree,arr,r(i),mid+1,e,qs,qe);
    
            return op(left,right);
        }

        void updateUtil(int *tree, int i, int s, int e, int qs, int qe, int val) {
    
            if(qe < s or qs > e) return;
            else if ( s == e ) tree[i] = val;
            else {
                int mid = (s+e)/2;
                updateUtil(tree,l(i),s,mid,qs,qe,val);
                updateUtil(tree,r(i),mid+1,e,qs,qe,val);

                tree[i] = op(tree[l(i)],tree[r(i)]);
            }
        }

    public:
        int query(int qs, int qe) {
            return queryUtil(tree,arr,0,0,n-1,qs,qe);
        }
        void update(int idx, int val) {
            updateUtil(tree,0,0,n-1,idx,idx,val);
        }
        void update(int qs, int qe, int val) {
            updateUtil(tree,0,0,n-1,qs,qe,val);
        }
        void print() {
            for( int i = 0; i < n; i++) cout<<tree[i]<<" ";
            cout<<"\n";
        }

        SegmentTree(int *brr, int size, int (&comp)(int ,int)) {
            n = size;
            tree = new int[4*n];
            arr = brr;
            op = comp;
            buildTree(tree,arr,0,0,n-1);
        }

};

int comp(int i, int j) {
    return i*j;
}

int main() {

    int n = 5;
    int arr[5] = {2,3,60,90,50};
    SegmentTree tree(arr,n,__gcd);
    printf(tree.query(1,3));
    printf(tree.query(2,4));
    printf(tree.query(0,2));
    
    return 0;
}

