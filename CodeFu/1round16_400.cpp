#include <string>
#include <vector>
using namespace std;

class MinSwaps
{
  public:
    int min(vector<int> a)
    {
       int brojac=0;
for(int i=0;i<a.size();i++)
{
  for(int j=i+1;j<a.size();j++)
{
    if(a[j]==i+1){
swap(a[i],a[j]);
brojac++;
}
}
}
 return brojac;     
  }
};