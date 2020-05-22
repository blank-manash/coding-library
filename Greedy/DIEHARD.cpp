#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

int findTime(int h, int a) {

    int cnt = 0;
    while( h > 0 and a > 0) {

        h+=3, a+=2;

        int fire_min = min(h-20,a+5);
        int water_min = min(h-5,a-10);

        if( fire_min > water_min) {
            h-=20,a+=5;
        }
        else h-=5,a-=10;
        cnt+=2;
    }
    return cnt;
}


void test() {

    int h,a;
    cin >> h >> a;
    cout << findTime(h,a) -1;
}

int32_t main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif
    int T; cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}