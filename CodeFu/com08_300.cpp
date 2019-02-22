#include <string>
#include <vector>
#include <cstring>
#include<queue>
using namespace std;
class HotPursuit
{


  

  public:
    int getTotalPaths(vector<string> adjacencyMatrix, vector<int> helicopters, int start)
    {

     vector<vector<int> > v;
	//vector<string> adjacencyMatrix;
	vector<int> vi;
        v.insert(v.begin(),helicopters.size()+1,vi);
int bb=0;
      for(int i=0;i<adjacencyMatrix.size();i++)
      {
            for(int j=0;j<adjacencyMatrix[i].size();j++)
             {
                  if(adjacencyMatrix[i][j]=='1')
                   v[i].push_back(j);
             }
        if(helicopters[i]==1)
bb++;
      }
if(bb==0)
return 0;
int res=0;
//int start;


queue<pair<int,string> > qi;
string ss="000000000000000000000000000000000000000000000000000";
ss[start]='1';
qi.push(make_pair(start,ss));

while(!qi.empty())
{
	int topi=qi.front().first;
	if(helicopters[topi]==1)
{
		res++;
qi.pop();
}
	else
	{
		string vk;
		vk=qi.front().second;
	
		qi.pop();
		for(int i=0;i<v[topi].size();i++)
		{
			
			if(vk[v[topi][i]]=='0')
			{
				vk[v[topi][i]]='1';
				qi.push(make_pair(v[topi][i],vk));
                           vk[v[topi][i]]='0';
			}
		}
	}
}
      return res;
  }
};