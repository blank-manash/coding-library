#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define fo(i,n) for(long long int i=0;i<n;i++)
#define Fo(i,k,n) for(long long int i=k;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x,y) fo(i,sizeof(x)/sizeof(x[0]))x[i]=y
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define uset unordered_set
#define umap unordered_map
#define endl "\n"
#define scanf(arr,n) fo(i,n)cin>>arr[i]
#define all(v) v.begin(),v.end()
#define printf(x) cout<<x<<"\n"
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int,vector<int>,greater<int>> pqmin;

void print (ll *arr, ll n) {fo(i,n){cout<<arr[i]<<" ";}cout<<"\n";}
bool isvaild (int i, int j, int n, int m) { return !( i < 0 or j < 0 or i > n-1 or j > m-1 );}
void print (vi &v) { for(int x : v) cout<<x<<" "; cout<<endl;}
void input(vi &v,int n) {fo(i,n){int tmp; cin>>tmp; v.push_back(tmp);}}
void input (int *arr, int n) {fo(i,n)cin>>arr[i];}

struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1,T2> &p) const 
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        return hash1^hash2;
    }
};
/*****************************MANASH**********************************/

int vparenthesis( string s) {

    int left = 0, right = 0;
    int answer = 0;
    int l = 0, r = 0;

    fo(i,s.size()) {
        char ch = s[i];

        if ( ch == '(') {
            left++;
            l = i;
        }
        else if( ch == ')') {
            right++;
            r = i;
        }
        if ( left == right ) answer = max(answer, 2*left);
        if ( right > left ) left = right = 0;
    } 

    left = right = l = r = 0;
    reverse(all(s));

    fo (i,s.size()) {

        char ch = s[i];
        if ( ch == ')') {
            right++;
            r = i;
        }
        else {
            left++;
            l = i;
        }
        if ( left == right ) answer = max(answer, 2*left);
        if ( right < left ) left = right = 0;
    }

    return answer;

}

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        printf(vparenthesis(s));
        

    }
    
	return 0;
}




//=================Functions==============
