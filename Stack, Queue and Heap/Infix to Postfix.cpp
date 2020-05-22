#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ====================== MANASH ======================== // 

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
string itp( string s) {
    stack<char> st;
    string ans;
    // operand push in ans.
    // operator, push if empty or higher precdence
    // ( push in st;
    // ) pop till empty or ( and discard (
    for ( char ch : s ) {
        if ( (ch >= 'a' and ch <='z') or ( ch>='A' and ch <='Z')) {
            ans+=ch;
        }
        else if ( ch == '(') st.push(ch);
        else if ( ch == ')') {
            while(!st.empty() and st.top() !='(') {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else {
            while(!st.empty() and prec(ch) <= prec(st.top())) {
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()) ans+=st.top(), st.pop();
    return ans;
    
}

void test() {
    string s;
    cin >> s;
   cout << itp(s);
}


int32_t main() {

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

void print(vector<int> &v) {

    for ( int x : v ) cout<<x<<" ";
    cout<<"\n";
}