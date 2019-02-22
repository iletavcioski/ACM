#include <string>
#include <vector>
using namespace std;

class PrimeLetters
{
  public:
    string getResult(string inputString)
    {
string ss="";
      for(int i=0;i<inputString.size();i++)
      {
         int b=inputString[i];
         ss+=inputString[i];
int brojac=0;
         for(int j=1;j<=b;j++)
         {
            if(b%j==0)
brojac++;
if(brojac>2)
break;
          }


if(brojac==2)
{
if(b<90)
ss+=inputString[i]+32;
else
ss+=inputString[i]-32;
}
      }
      return ss;
  }
};