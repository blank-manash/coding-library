#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int count = 0;
		vector<int> a(n,0);
		unordered_multiset<int> ums;
		for(int i=0;i<n;i++) cin>>a[i];
		
		for(int i=0;i<n;i++)
		{
		    int tmp = k - a[i];
		    if(ums.find(tmp) != ums.end()) count+=ums.count(tmp);
		    ums.insert(a[i]);
		}

		cout<<count<<endl;
	}
}
