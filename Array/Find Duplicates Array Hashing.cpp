#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (int *arr, int n);
void print (vector<int> &v);
void input(vector<int> &v, int n);

void printDuplicates(int *a, int n) {
   
   // Use the array as HASHMAP.
   // Elements are in 0 -- n-1
   // so original element can be retrived by %n;
   // we add a frequency factor k and each element is k*i
   // use index of array as keys.

   bool found = false;
   for( int i = 0; i < n; i++) {
       int index = a[i]%n;
       a[index] = a[index] + n;
   }

   for(int i = 0; i < n; i++) {
       if(a[i]/n > 1) found = true, cout <<i<<" ";
   }
   if(not found ) cout << -1;
}
