#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
struct node
{
	int maxi1;
	int maxi2;
};
node segtree[400004];
void build(int l,int r,int p)
{
	if(l==r)
	{
		segtree[p].maxi1=v[l];
		segtree[p].maxi2=-1e8;
		return;
	}
	build(l,(l+r)/2,2*p);
	build((l+r)/2+1,r,2*p+1);
	vector<int> vv;
	vv.push_back(segtree[2*p].maxi1);
	vv.push_back(segtree[2*p].maxi2);
	vv.push_back(segtree[2*p+1].maxi1);
	vv.push_back(segtree[2*p+1].maxi2);
	sort(vv.begin(),vv.end());
	reverse(vv.begin(),vv.end());
	segtree[p].maxi1=vv[0];
	segtree[p].maxi2=vv[1];
}
void update(int l,int r,int p,int pos,int val)
{
	if(l>pos||r<pos)
		return;
	if(l==r)
	{
		segtree[p].maxi1=val;
		segtree[p].maxi2=-1e8;
		return;
	}
	update(l,(l+r)/2,2*p,pos,val);
	update((l+r)/2+1,r,2*p+1,pos,val);
	vector<int> vv;
	vv.push_back(segtree[2*p].maxi1);
	vv.push_back(segtree[2*p].maxi2);
	vv.push_back(segtree[2*p+1].maxi1);
	vv.push_back(segtree[2*p+1].maxi2);
	sort(vv.begin(),vv.end());
	reverse(vv.begin(),vv.end());
	segtree[p].maxi1=vv[0];
	segtree[p].maxi2=vv[1];
}
node query(int l,int r,int p,int i,int j)
{
	if(j<l||r<i){
		node bb;
		bb.maxi1=-1e8;
		bb.maxi2=-1e8;
		return bb;
	}
	if(l>=i&&r<=j)
	{
		return segtree[p];
	}
	node a1=query(l,(l+r)/2,2*p,i,j);
	node a2=query((l+r)/2+1,r,2*p+1,i,j);
	vector<int> vv;
	vv.push_back(a1.maxi1);
	vv.push_back(a1.maxi2);
	vv.push_back(a2.maxi1);
	vv.push_back(a2.maxi2);
	node bb;
	sort(vv.begin(),vv.end());
	reverse(vv.begin(),vv.end());
	bb.maxi1=vv[0];
	bb.maxi2=vv[1];
	return bb;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	int q;
	cin>>q;
	build(0,n-1,1);
 
	for(int qq=0;qq<q;qq++)
	{
		char a;
		cin>>a;
		if(a=='U')
		{
			int b,c;
			cin>>b>>c;
			b--;
			update(0,n-1,1,b,c);
		}
		if(a=='Q')
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			node aa=query(0,n-1,1,a,b);
			cout<<aa.maxi1+aa.maxi2<<endl;
		}
	}
	return 0;
} 