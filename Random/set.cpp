#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class disjoint_set { //Rank is the value in the size of the parent index;
    public:
    int *set;
    int size;
    public:
    disjoint_set(int n) {
        set = new int[n+1];
        size = n;
        for(int i = 0; i<=n+1; i++) set[i] = -1;
    }

    int find (int u) {
        int x = u;
        while(set[x] > 0) x = set[x];
        return x;
    }

    int rank(int x) {
        int y = find(x);
        return abs(set[y]);
    }
    int parent ( int x ) {
        return set[x] < 0 ? x : set[x]; 
    }

    void unionset (int x, int y) {

        int xrank = rank(x);
        int yrank = rank(y);

        if( xrank > yrank ) {
            set[parent(y)] = parent(x);
            set[parent(x)] = -(xrank + yrank);
        }
        else {
            set[parent(x)] = parent(y);
            set[parent(y)] = -(xrank + yrank); 
        }
    }
};


void print(int *arr, int n) {
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    disjoint_set s(10);
    print(s.set,s.size);
    s.unionset(10,5);
    print(s.set,s.size);
    s.unionset(2,4);
    print(s.set,s.size);
    s.unionset(10,2);
    print(s.set,s.size);
    cout<<s.find(2)<<endl;
    
    return 0;
}
