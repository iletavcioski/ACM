#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp1(500001,0);
vector<int> dp2(500001,0);
 
vector<int> dpi(500001,0);
vector<vector<int> > v;
int brojac=0;
void dfs1(int x,int prev)
{
    dp1[x]=0;
    bool isleaf=false;
    for(int i=0;i<v[x].size();i++)
    {
        int next=v[x][i];
        int edge=1;
        if(next==prev)
            continue;
        isleaf=true;
        dfs1(next,x);
        if(dp1[x]<dp1[next]+edge)
        {
            dp2[x]=dp1[x];
            dp1[x]=dp1[next]+edge;
            dpi[x]=next;
        }
        else if(dp2[x]<dp1[next]+edge)
        {
            dp2[x]=dp1[next]+edge;
        }
    }
    if(!isleaf)
    {
        dpi[x]=x;
    }
    return ;
}
void dfs2(int x,int prev,int edge)
{
    if(prev==-1) {
 
        for(int i=0;i<v[x].size();i++)
        {
            if(v[x][i]!=prev) {
                dfs2(v[x][i], x,1);
            }
        }
        return;
    }
    int krak=edge;
    if(dp1[prev]>dp2[prev])
    {
        if(dpi[prev]==x)
            krak+=dp2[prev];
        else
            krak+=dp1[prev];
    }
    else {
        krak += dp2[prev];
    }
    dp2[x]=max(dp2[x],krak);
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=prev) {
            dfs2(v[x][i], x,1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
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
    
            dfs1(0, -1);
            dfs2(0, -1,-1);
     
    int maxi=0;
    for(int i=0;i<n;i++)
    {
       if(i)
        cout<<" ";
        cout<<max(dp1[i],dp2[i]);
    }
    
    cout<<endl;
    return 0;
}