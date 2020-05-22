#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define dbl cout <<"--------------\n"
#define a(x) x.begin(),x.end()
typedef vector<int> vi;
typedef pair<int,int> pi;
void print (vector<int> &v);
void input(vector<int> &v, int n);
// ====================== MANASH ======================== // 

int eval(string str) {
    stack<int> s;

    for(char ch : str) {
        if( ch >='0' and ch <='9')
            s.push(ch-'0');
        else {
            assert(s.size() > 1);
            int y = s.top();    s.pop();
            int x = s.top();    s.pop();
            //db(x),db(y);
            int z;
            switch (ch)
            {
            case '*':
                z = x*y;
                break;
            case '+':
                z = x+y;
                break;
            case '-':
                z = x-y;
                break;
            case '/':
                z = x/y;
                break;
            default:
                break;
            }
            //db(z);
            s.push(z);
            //cout << "--------\n";
        }
    }

    return s.top();
}


void test() {
    string s;
    cin >> s;
    cout << eval(s); 
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