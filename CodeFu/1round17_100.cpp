#include <string>
#include <vector>
using namespace std;

class JobFair
{
  public:
    int maxStands(vector<int> startingStand, vector<int> endingStand, int N)
    {
int brojac=0;
     for(int i=0;i<startingStand.size();i++)
{
bool cc=true;
for(int j=0;j<startingStand.size();j++)
{
   if(startingStand[j]<=endingStand[i]&&endingStand[j]>=startingStand[i]&&i!=j)
     cc=false;
}
if(cc)
brojac++;
}
      return brojac;
  }
};