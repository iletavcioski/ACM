#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class LectureSchedule
{
  public:
    int maxLectures(vector<int> start, vector<int> end)
    {
    set<int> v;
    map<int,int> m;
    for(int i=0;i<start.size();i++)
    {
      v.insert(start[i]);
    }
    for(int i=0;i<end.size();i++)
    {
        v.insert(end[i]);
    }
    int br=1;
    for(set<int>::iterator it=v.begin();it!=v.end();it++)
    {
        m[*it]=br;
        br++;
    }
    vector<vector<int> > graf;
    vector<int> vec;
    graf.insert(graf.begin(),300,vec);
    int maxi=0;
    for(int i=0;i<end.size();i++)
    {
        maxi=max(maxi,m[end[i]]);
        for(int j=0;j<start.size();j++)
        {
            if(start[j]<end[i])
            {
                graf[m[end[i]]].push_back(m[start[j]]);
            }
        }
    }
    vector<int> dp(maxi+1,0);
    for(int i=1;i<=maxi;i++)
    {
        dp[i]=max(dp[i],dp[i-1]);
        for(int j=0;j<graf[i].size();j++)
        {
            dp[i]=max(dp[i],dp[graf[i][j]]+1);
        }
    }
    return dp[maxi];
  }
};