#include <string>
#include <vector>
using namespace std;

class BlindDaleks
{
  public:
    int exterminate(vector<string> map)
    {
int brojac=0;
     for(int i=0;i<map.size();i++)
{
  for(int j=0;j<map[i].size();j++)
{
   if(map[i][j]=='E')
{
  for(int k=j;k<map[i].size();k++)
{
     if(map[i][k]=='C')
{
map[i][k]='-';
brojac++;
}
}
}
if(map[i][j]=='W')
{
  for(int k=j;k>=0;k--)
{
     if(map[i][k]=='C')
{
map[i][k]='-';
brojac++;
}
}
}
if(map[i][j]=='S')
{
  for(int k=i;k<map.size();k++)
{
     if(map[k][j]=='C')
{
map[k][j]='-';
brojac++;
}
}
}
if(map[i][j]=='N')
{
  for(int k=i;k>=0;k--)
{
     if(map[k][j]=='C')
{
map[k][j]='-';
brojac++;
}
}
}
}
}
      return brojac;
  }
};