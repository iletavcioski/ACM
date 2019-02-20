#include <string>
#include <vector>
using namespace std;

class Hodor
{
  public:
    int hodor(string hodor)
    {
     for(int i=0;i<hodor.size();i++)
   {
      if(hodor[i]>=60&&hodor[i]<=90)
                           hodor[i]+=32;
   }
int brojac=0;
for(int i=0;i<hodor.size()-4;i++)
{
   if(hodor[i]=='h'&&hodor[i+1]=='o'&&hodor[i+2]=='d'&&hodor[i+3]=='o'&&hodor[i+4]=='r')
brojac++;
}
      return brojac;
  }
};