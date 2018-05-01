#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll segtree[300001];
ll lazy[300001];
ll n;
vector<ll> v;
void build(ll l,ll r,ll p)
{
	lazy[p]=0;
	if(l==r)
		segtree[p]=v[l];
	else
	{
		build(l,(l+r)/2,2*p);
		build((l+r)/2+1,r,2*p+1);
		segtree[p]=segtree[2*p]+segtree[2*p+1];
	}
}
void update(ll i,ll j,ll val,ll l,ll r,ll p)
{
	if(lazy[p]>0)
	{
		segtree[p]+=lazy[p]*(r-l+1);
		if(l!=r)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
		}
		lazy[p]=0;
	}
	if(i>r||j<l)
		return;
	if(i<=l&&j>=r)
	{
		segtree[p]+=val*(r-l+1);
		if(r!=l)
		{
			lazy[2*p]+=val;
			lazy[2*p+1]+=val;
		}
	}
	else
	{
		update(i,j,val,l,(l+r)/2,2*p);
		update(i,j,val,(l+r)/2+1,r,2*p+1);
		segtree[p]=segtree[2*p]+segtree[2*p+1];
	}
}
ll query(ll i,ll j,ll l,ll r,ll p)
{
	if(lazy[p]>0)
	{
		segtree[p]+=lazy[p]*(r-l+1);
		if(l!=r)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
		}
		lazy[p]=0;
	}
	if(i>r||j<l)
		return 0;
	if(l>=i&&j>=r)
		return segtree[p];
	return (query(i,j,l,(l+r)/2,2*p)+query(i,j,(l+r)/2+1,r,2*p+1));
}
int main()
{
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		cin>>n;
		int q;
		cin>>q;
		for(int i=0;i<n;i++)
		{
			v.push_back(0);
		}
		build(0,n-1,1);
 
		for(int i=0;i<q;i++)
		{
			int bb;
			cin>>bb;
			if(bb==0)
			{
				ll a,b;
				ll c;
				cin>>a>>b>>c;
				a--;
				b--;
				update(a,b,c,0,n-1,1);
			}
			else
			{
				ll a,b;
				cin>>a>>b;
				a--;
				b--;
				cout<<query(a,b,0,n-1,1)<<endl;
			}
		}
	}
	return 0;
} 