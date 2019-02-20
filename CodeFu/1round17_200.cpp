#include <string>
#include <vector>
using namespace std;

class Brackets
{
  public:
    int longest(string brackets)
    {
int res=brackets.size();
int brojac=0;
     for(int i=0;i<brackets.size();i++)
{
   if(brackets[i]=='[')
brojac++;
else
brojac--;
if(brojac<0){
brojac=0;
res--;}
}

      return res-brojac;
  }
};