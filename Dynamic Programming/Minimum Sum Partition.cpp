#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
#define umap unordered_map
#define db(x) cout << #x << " == " << x << ";\n"
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

const int inf = 1e5+7;
// ===================== MANASH =================== //

void test() {

	int n;
	cin >> n;
	vi arr;
	int s = 0;
	arr.push_back(0);
	for( int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
		s += t;
	}
	int m = s/2 + 4;
	bool dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for( int i = 0; i <= n; i++) dp[i][0] = true;
	
	for( int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(arr[i] <= j) dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i]];
			else dp[i][j] = dp[i-1][j];
		}
	}

	int ans = s;
	for( int i = m; i > 0; i--) {
		
		if(dp[n][i]) ans = min(ans,abs(s - 2*i));
	}

	cout << ans;

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