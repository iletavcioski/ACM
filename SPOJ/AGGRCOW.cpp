#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t)
	{
		t--;
	int n;
	cin>>n;
	int c;
	cin>>c;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int l=0,r=1000000000;
	int maxi=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if((l+r)%2==1)
			mid++;
		int brojce=v[0];
		int brojac=1;
		int mini=(1000000001);
		for(int i=1;i<v.size();i++)
		{
			if(v[i]-brojce>=mid)
			{
				mini=min(mini,(v[i]-brojce));
				brojce=v[i];
				brojac++;
				
			}
		}
		if(brojac>=c)
		{
			maxi=max(maxi,mid);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<maxi<<endl;
	}
	return 0;
} 