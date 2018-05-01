#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mp make_pair 
#define pb push_back 
#define f first 
#define s second 
vector<pair<int,int> > v1(100001,mp(-1,1e9)),v2(100001,mp(-1,1e9));
vector<vector<int> > v;
pair<int,int> dfs1(int x,int prev)
{
    int maxi1=0;
    int maxi2=0;
    int ind1=1e9;
    int ind2=1e9;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==prev)
            continue;
        pair<ll,int> b=dfs1(v[x][i],x);
        if(b.f+1>maxi1||(b.f+1==maxi1&&b.s<ind1))
        {
            maxi2=maxi1;
            ind2=ind1;
            maxi1=b.f+1;
            ind1=b.s;
        }
        else if(b.f+1>maxi2||(b.f+1==maxi2&&b.s<ind2))
        {
            maxi2=b.f+1;
            ind2=b.s;
        }
    }
    v1[x]=(mp(maxi1,ind1));
    v2[x]=(mp(maxi2,ind2));
    return mp(maxi1,ind1);
}
void dfs2(int x,int prev)
{
    if(prev==-1)
    {
        for(int i=0;i<v[x].size();i++)
        {
            if(v[x][i]!=prev)
                dfs2(v[x][i],x);
        }
        return;
    }
    
    ll maxi1=-2e9;
    int ind1=1e8;
    ll maxi2=-2e9;
    int ind2=1e8;
    if(v1[x].f>maxi1||(v1[x].f==maxi1&&v1[x].s<ind1))
        {
            if(v1[x].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v1[x].f;
            ind1=v1[x].s;
        }
        else if(v1[x].f>maxi2||(v1[x].f==maxi2&&v1[x].s<ind2))
        {
            if(v1[x].s!=ind1)
            {
                maxi2=v1[x].f;
                ind2=v1[x].s;
            }
        }
    if(v2[x].f>maxi1||(v2[x].f==maxi1&&v2[x].s<ind1))
        {
            if(v2[x].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v2[x].f;
            ind1=v2[x].s;
        }
        else if(v2[x].f>maxi2||(v2[x].f==maxi2&&v2[x].s<ind2))
        {
            if(v2[x].s!=ind1)
            {
                maxi2=v2[x].f;
                ind2=v2[x].s;
            }
        }
    if(v1[prev].f+1>maxi1||(v1[prev].f+1==maxi1&&v1[prev].s<ind1))
        {
            if(v1[prev].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v1[prev].f+1;
            ind1=v1[prev].s;
        }
        else if(v1[prev].f+1>maxi2||(v1[prev].f+1==maxi2&&v1[prev].s<ind2))
        {
            if(v1[prev].s!=ind1)
            {
                maxi2=v1[prev].f+1;
                ind2=v1[prev].s;
            }
        }
    if(v2[prev].f+1>maxi1||(v2[prev].f+1==maxi1&&v2[prev].s<ind1))
        {
            if(v2[prev].s!=ind1)
            {
                ind2=ind1;
                maxi2=maxi1;
            }
            maxi1=v2[prev].f+1;
            ind1=v2[prev].s;
        }
        else if(v2[prev].f+1>maxi2||(v2[prev].f+1==maxi2&&v2[prev].s<ind2))
        {
            if(v2[prev].s!=ind1)
            {
                maxi2=v2[prev].f+1;
                ind2=v2[prev].s;
            }
        }
    v1[x]=mp(maxi1,ind1);
    v2[x]=mp(maxi2,ind2);
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev)
            dfs2(v[x][i],x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,v1[i].f+v2[i].f);
    }
    cout<<maxi<<endl;
    return 0;
}