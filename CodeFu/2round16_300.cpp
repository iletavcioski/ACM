#include <string>
#include <vector>
using namespace std;

class JapaneseDrones
{
  public:
    string calculateDroneCapacity(int n, int m, vector<int> a, vector<int> b)
    {
   vector<pair<long long,long long> > v;
     for(int i=0;i<m;i++)
{
v.push_back(make_pair(b[i],a[i]));
}
  
   sort(v.begin(),v.end());
reverse(v.begin(),v.end());
long long kk=0;
for(int i=0;i<v.size();i++)
{
    if(v[i].second<=n)
    {
        kk+=v[i].first*v[i].second;
      n-=v[i].second;
     }
else
{
    kk+=n*v[i].first;
n=0;
}
if(n==0)
break;
}
   
    
    
string ss;
 while(kk>0)
{
ss+=((kk%10)+'0');
kk/=10;
}
reverse(ss.begin(),ss.end());
      return ss;
  }
};