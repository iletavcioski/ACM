#include <string>
#include <vector>
#include<set>
#include<cstring>
using namespace std;

class FloatyBoat
{
int dist[100];
int mini;
vector<vector<int> > v;
void dfs(int x,int d)
{
	dist[x]=d;
	if(v[x].size()==0)
		mini=min(mini,d);
	for(int i=0;i<v[x].size();i++)
		dfs(v[x][i],d+1);
}
  public:
    int balanceTree(vector<int> from, vector<int> to)
    {
      vector<int> vi;
	v.insert(v.begin(),100,vi);
	set<int> ss;
	for(int i=0;i<from.size();i++)
	{
		v[from[i]].push_back(to[i]);
		ss.insert(from[i]);
		ss.insert(to[i]);
	}
	int minii=99999;
	
		memset(dist,-1,sizeof(dist));
		 mini=99999;
		 int brojac=0;
               dfs(from[0],0);
		for(int i=0;i<100;i++)
		{
			if(dist[i]!=-1&&dist[i]>mini+1)
				brojac++;
		}
		minii=min(minii,brojac);
	
return minii;
  }
};