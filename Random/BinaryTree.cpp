#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define deb(x) cout<<" #x "<<x<<endl;
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define uset unordered_set
#define umap unordered_map



struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        left = right = NULL;
        data = x;
    }
};

Node *insert(Node *root,int k) {
    if(root == NULL) return new Node(k);
    if(root->data > k) root->left = insert(root->left,k);
    else if(root->data < k) root->right = insert(root->right,k);
    return root;
}

//Builds Balanced Binary Tree.

Node* inorder(Node *root, int *arr, int start, int end) {
    if(start<=end){
    int mid = (start+end)/2;
    if(root == NULL) root =  new Node(arr[mid]);
    root->left = inorder(root->left,arr,start,mid-1);
    root->right = inorder(root->right,arr,mid+1,end);
    return root;
    }
    return NULL;
}

void preorder(Node *node) {
    if(node == NULL) return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Node *root = NULL;
    	//middle element;
        int arr[n];
    	fo(i,n) cin>>arr[i];

    	root = inorder(root,arr,0,n-1);
        preorder(root);

    	cout<<endl;

    }
	return 0;
}
