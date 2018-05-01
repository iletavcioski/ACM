#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
int ft[200010];
int cc;
vector<bool> visi(200002,0);
void update(int x,int val)
{
    int i=x;
	if(i==0)
		return;
    while(i<=200000)
    {
        ft[i]+=val;
        i+=(i&-i);
    }
}
int query(int x)
{
    int i=x;
    int broj=0;
    while(i>0)
    {
        broj+=ft[i];
        i-=(i&-i);
    }
    return broj;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int Q;
    cin>>Q;
    unordered_map<ll,int> m;
    vector<pair<ll,char> > v;
    vector<pair<char,ll> > q;
    for(int i=0;i<Q;i++)
    {
        char a;
        ll b;
        cin>>a>>b;
        if(a=='I'||a=='D'||a=='C')
        {
            v.push_back(make_pair(b,a));
        }
        q.push_back(make_pair(a,b));
    }
	vector<ll> vec(200002,-1);
    sort(v.begin(),v.end());
	int j=1;
    for(int i=0;i<v.size();i++)
    {
		if(v[i].second=='I'||v[i].second=='D')
		{
			if(!i)
			{
				m[v[i].first]=j;
				vec[j]=(v[i].first);
				j++;
			}
			else if(v[i].first!=v[i-1].first)
			{
				m[v[i].first]=j;
				vec[j]=(v[i].first);
				j++;
			}
		}
		else
		{
			if(!i)
			{
				m[v[i].first]=j;
				vec[j]=(v[i].first);
				j++;
			}
			else if(v[i].first!=v[i-1].first)
			{
				m[v[i].first]=j;
				vec[j]=(v[i].first);
				j++;
			}
		}
    }
    for(int i=0;i<q.size();i++)
    {
        char a=q[i].first;
        if(a=='I')
        {
			int b=m[q[i].second];
            if(!visi[b])
            {
                visi[b]=true;
                update(b,1);
            }
        }
        else if(a=='D')
        {
			int b=m[q[i].second];
            if(visi[b])
            {
                visi[b]=false;
                update(b,-1);
            }
        }
        else if(a=='K')
        {
			int b=q[i].second;
			int l=1,r=200000;
			int maxi=2e6;
			if(b<=0)
			{
				cout<<"invalid"<<endl;
				continue;
			}
			if(query(200000)<b)
			{
				cout<<"invalid"<<endl;
				continue;
			}
			while(l<=r)
			{
				int mid=(l+r)/2;
				int aa=query(mid);
				if(aa>=b)
				{
					r=mid-1;
					if(aa==b)
						maxi=min(maxi,mid);
				}
				else
					l=mid+1;
			}
			cout<<vec[maxi]<<endl;
        }
        else
        {
			int b=m[q[i].second];
            cout<<query(b-1)<<endl;
        }
    }
    return 0;
}