#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int sum;
    int prefix;
    int suffix;
    int maxi;
}segtree[2400001];
int v[500005];
node propagate(node a,node b)
{
    node g;
    g.prefix=max(a.prefix,a.sum+b.prefix);
    g.sum=a.sum+b.sum;
    g.suffix=max(b.suffix,b.sum+a.suffix);
    g.maxi=max(a.maxi,max(b.maxi,a.suffix+b.prefix));
    return g;
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        node g;
        g.maxi=v[l];
        g.sum=v[l];
        g.suffix=v[l];
        g.prefix=v[l];
        segtree[p]=g;
        return;
    }
    build(l,(l+r)/2,2*p);
    build((l+r)/2+1,r,2*p+1);
    segtree[p]=propagate(segtree[2*p],segtree[2*p+1]);
}
void update(int l,int r,int i,int p,int val)
{
    if(l==i&&r==i)
    {
        segtree[p].suffix=val;
        segtree[p].prefix=val;
        segtree[p].sum=val;
        segtree[p].maxi=val;
        return;
    }
    if(i<l||r<i)
        return;
    update(l,(l+r)/2,i,2*p,val);
    update((l+r)/2+1,r,i,2*p+1,val);
    segtree[p]=propagate(segtree[2*p],segtree[2*p+1]);
}
node query(int l,int r,int i,int j,int p)
{
    if(l>=i&&r<=j)
        return segtree[p];
    if(l>j||r<i)
    {
        node g;
        g.sum=0;
        g.prefix=-1e9;
        g.suffix=-1e9;
        g.maxi=-1e9;
        return g;
    }
    return propagate(query(l,(l+r)/2,i,j,2*p),query((l+r)/2+1,r,i,j,2*p+1));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		build(0,n-1,1);
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
				int i1,j1,i2,j2;
				scanf("%d %d %d %d",&i1,&j1,&i2,&j2);
				i1--;
				j1--;
				i2--;
				j2--;
					if(j1>=i2)
					{
						int m1,m2,m3;
						m3=query(0,n-1,i2,j1,1).maxi;
						int a1=query(0,n-1,i1,j1,1).suffix;
						int a2=query(0,n-1,j1+1,j2,1).prefix;
						m2=max(a1,a2+a1);
						int b1=query(0,n-1,i1,i2,1).suffix;
						int b2=query(0,n-1,i2+1,j2,1).prefix;
						m1=max(b1,b1+b2);
						printf("%d\n",max(m1,max(m2,m3)));
					}
					else
					{
						int a=query(0,n-1,j1+1,i2-1,1).sum;
						int b=query(0,n-1,i1,j1,1).suffix;
						int c=query(0,n-1,i2,j2,1).prefix;
						if(j1+1>i2-1)
							a=0;
						printf("%d\n",a+b+c);
					}
		}
	}
    return 0;
} 