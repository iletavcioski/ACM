#include <string>
#include<algorithm>
#include <vector>
using namespace std;

class DroneRacing
{
  public:
    int winner(int N, string races)
    {
	vector<int> v;
for(int i=1;i<=N;i++)
v.push_back(i);
int ii=0,j=N-1;
vector<int> v2;
       for(int i=0;i<races.size();i++)
{
if(races[i]=='1')
v2.push_back(v[ii]);
else
v2.push_back(v[j]);
ii++;
j--;
if(ii>j){
v=v2,v2.clear();
sort(v.begin(),v.end());
ii=0,j=v.size()-1;
}
}
      return v[0];
  }
};