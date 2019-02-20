#include <string>
#include <vector>
using namespace std;

class TheLoneInteger
{
  public:
    int findIt(vector<int> a)
    {
    vector<int> v(1001,0);
for(int i=0;i<a.size();i++)
v[a[i]]++;
for(int i=0;i<v.size();i++)
{
     if(v[i]==1)
return i;
}
      return 0;
  }
};