#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int j=1;
	while(j<=t)
	{
		j++;
		int n,m;
		cin>>n>>m;
		vector<vector<int> > v;
		vector<int> vec;
		v.insert(v.begin(),n+1,vec);
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		vector<int> visi(n+1,0);
		bool cc=true;
		for(int i=0;i<n;i++)
		{
			if(!visi[i])
			{
				queue<int> qi;
				qi.push(i);
				queue<int> qs;
				qs.push(1);
				visi[i]=1;
				while(!qi.empty())
				{
					if(cc==false)
						break;
					int topi=qi.front();
					qi.pop();
					int tops=qs.front();
					qs.pop();
					int treba;
					if(tops==1)
						treba=2;
					else
						treba=1;
					for(int ii=0;ii<v[topi].size();ii++)
					{
						if(visi[v[topi][ii]]&&visi[v[topi][ii]]!=treba)
						{
							cc=false;
							break;
						}
						if(!visi[v[topi][ii]])
						{
							visi[v[topi][ii]]=treba;
							qi.push(v[topi][ii]);
							qs.push(treba);
						}
					}
				}
			}
		}
		if(cc)
		{
			cout<<"Scenario #"<<j-1<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}
		else
		{
			cout<<"Scenario #"<<j-1<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
	}
	return 0;
}