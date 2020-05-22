// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLevelSum(Node* root) {
    // Your code here
    if ( root == NULL ) return 0;
    queue<Node*> q;
    int lsum = root->data;
    q.push(root);
    while(!q.empty()) {

        int n = q.size();
        int sum = 0;
        while(n--) {

            Node* front = q.front(); q.pop();
            Node *left = front->left;
            Node *right = front->right;
            if(left) q.push(left),sum+=left->data;
            if(right) q.push(right),sum+=right->data;
        }
        if(sum) lsum = max(sum,lsum);
    }
    return lsum;
    
}
