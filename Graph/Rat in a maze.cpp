
#include <bits/stdc++.h>
using namespace std;

#define MAX 5

bool valid (int i, int j, int n) {
    return !(i < 0 or j < 0 or i > n-1 or j > n-1);
}

string mover = "DLRU";
int dir1[4] = {1,0,0,-1}; //i
int dir2[4] = {0,-1,1,0}; //j

// ELEGENCE // 

void backtrack( vector<string> &v, string s, int i, int j, int m[MAX][MAX], int n) {

    if( not valid(i,j,n) or m[i][j] == 0) return;
    if( i == n-1 and j == n-1) {
        if( !s.empty()) v.push_back(s);
        return;
    }
    m[i][j] = 0;
    for(int k = 0; k < 4; k++) {

        backtrack(v,s+mover[k],i+dir1[k],j+dir2[k],m,n);
    }
    m[i][j] = 1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    
    vector<string> res;
    string s = "";
    backtrack(res,s,0,0,m,n);
    //if(res.size() >1 ) sort(res.begin(),res.end());
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

