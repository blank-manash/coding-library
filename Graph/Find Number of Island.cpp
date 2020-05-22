// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

static int cnt = 0;
int n,m;

void island( vector<int> arr[], int i, int j ) {
    
    if( i < 0 or j < 0 or i > n-1 or j > m-1 or arr[i][j] == 0) return;
    arr[i][j] = 0;
    island(arr,i+1,j);
    island(arr,i,j+1);
    island(arr,i-1,j);
    island(arr,i,j-1);
    island(arr,i-1,j-1);
    island(arr,i+1,j+1);
    island(arr,i+1,j-1);
    island(arr,i-1,j+1);
}

int findIslands(vector<int> arr[], int N, int M) {

    // Your code here
    cnt = 0;
    n = N, m = M;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1)  cnt++,island(arr,i,j); //Important Step.
        }
    }

    return cnt;
}
