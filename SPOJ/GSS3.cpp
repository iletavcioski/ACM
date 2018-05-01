#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int sum;
    int prefix;
    int suffix;
    int maxi;
}segtree[400001];
int v[400001];
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
        int a;
        scanf("%d",&a);
        if(!a)
        {
            int x,val;
            scanf("%d %d",&x,&val);
            x--;
            update(0,n-1,x,1,val);
        }
        else
        {
            int i,j;
            scanf("%d %d",&i,&j);
            i--;
            j--;
            printf("%d\n",query(0,n-1,i,j,1).maxi);
        }
    }
    return 0;
}