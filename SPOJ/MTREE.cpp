#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
vector<vector<pair<int,ll> > > v;
vector<ll> dp(100001,0);
ll brojac=0;
ll dfs(int x,int prev)
{
    vector<ll> vv;
    ll zbir=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].first==prev)
            continue;
        ll broj=(((dfs(v[x][i].first,x)*v[x][i].second)%mod+v[x][i].second)%mod);
        dp[x]+=broj;
        dp[x]%=mod;
        vv.push_back(broj);
        zbir=(zbir+broj)%mod;
    }
    for(int i=0;i<vv.size();i++)
    {
		brojac=(brojac+vv[i])%mod;
        zbir-=vv[i];
        while(zbir<0)
            zbir+=mod;
        zbir%=mod;
        brojac=(brojac+((zbir*vv[i])%mod))%mod;
    }
    return dp[x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    vector<pair<int,ll> > vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;
        b--;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    dfs(0,-1);
    cout<<brojac<<endl;
    return 0;
} 