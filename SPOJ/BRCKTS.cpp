#include<iostream>
#include<string>
using namespace std;
string ss;
struct node
{
	int mini;
	int zbir;
};
node segtree[100001];
void build(int l,int r,int p)
{
	if(l==r)
	{
		if(ss[l]=='(')
			segtree[p].mini=1;
		else
			segtree[p].mini=-1;
		segtree[p].zbir=segtree[p].mini;
		return;
	}
	build(l,(l+r)/2,2*p);
	build((l+r)/2+1,r,2*p+1);
	segtree[p].mini=min(segtree[2*p].mini,segtree[2*p].zbir+segtree[2*p+1].mini);
	segtree[p].zbir=segtree[2*p].zbir+segtree[2*p+1].zbir;
}
void update(int l,int r,int p,int ind)
{
	if(r<ind||l>ind)
		return;
	if(l==r)
	{
		segtree[p].mini*=-1;
		segtree[p].zbir=segtree[p].mini;
		return;
	}
 
	update(l,(l+r)/2,2*p,ind);
	update((l+r)/2+1,r,2*p+1,ind);
	segtree[p].mini=min(segtree[2*p].mini,segtree[2*p].zbir+segtree[2*p+1].mini);
	segtree[p].zbir=segtree[2*p].zbir+segtree[2*p+1].zbir;
}
int main()
{
	ios_base::sync_with_stdio(false);
	for(int t=0;t<10;t++)
	{
		cout<<"Test "<<t+1<<":"<<endl;
		for(int i=0;i<100000;i++)
		{
		segtree[i].mini=10000;
		segtree[i].zbir=100000;
		}
		int n;
		cin>>n;
		cin>>ss;
		build(0,n-1,1);
		int k;
		cin>>k;
		for(int i=0;i<k;i++)
		{
			int a;
			cin>>a;
			a--;
			if(a==-1)
			{
				if(segtree[1].mini==0&&segtree[1].zbir==0)
				{
					cout<<"YES"<<endl;
				}
				else
					cout<<"NO"<<endl;
			}
			else
			{
				update(0,n-1,1,a);
			}
		}
	}
	return 0;
}