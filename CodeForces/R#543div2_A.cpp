#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	int n, m , k;
	cin >>n>>m>>k;
	vector<pair<int,int> > vec;
	vector<vector<pair<int,int> > > v(m+1,vec);
	vector<int> c;
	for (int i = 0; i < n; i++) {
		int a;
		cin>>a;
		c.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin>>a;
		v[a].push_back(make_pair(c[i], i + 1));
	}
	for (int i = 1; i <= m; i++)
	{
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
	}
	int br = 0;
	for (int i = 0; i < k; i++) {
		int a;
		cin>>a;
		bool cc=true;
		for (int j = 1; j <= m; j++) {
			if (v[j][0].second == a)
				cc=false;
		}
		if (cc)
			br++;
	}
	cout<<br<<endl;
	return 0;
}