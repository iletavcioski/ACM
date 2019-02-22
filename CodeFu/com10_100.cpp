#include <string>
#include <vector>
using namespace std;

class RosoTheDictator
{
  public:
    int mostRoads(int n, vector<string> roadMap)
    {
int brojac=0;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(roadMap[i][j]=='1')
brojac++;
}
}
brojac/=2;
      return brojac-n+1;
  }
};