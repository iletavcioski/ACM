#include <string>
#include <vector>
using namespace std;

class CapsLock
{
  public:
    int fewerPushes(string message)
    {
bool cc=false;
int brojac=0;
      for(int i=0;i<message.size();i++)
{
    if(message[i]>=65&message[i]<=90&&cc==false)
{
brojac++;
cc=true;
}
if(message[i]>=97&&message[i]<=122&&cc==true)
{
brojac++;
cc=false;
}
}
      return brojac;
  }
};