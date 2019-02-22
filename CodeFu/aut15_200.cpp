#include <string>
#include <vector>
using namespace std;

class HuffmanDecoder
{
  public:
    string getText(string codedString)
    {
    string kkraj="";
   string ss="";
      for(int i=0;i<codedString.size();i++)
     {
        ss+=codedString[i];
        if(ss=="0")
{
        kkraj+='A';
ss="";
}
         else if(ss=="10")
{
        kkraj+='B';
ss="";
}
         else if(ss=="110")
{
         kkraj+='C';
ss="";
}
         else if(ss=="1110")
{
         kkraj+='D';
ss="";
}
         else if(ss=="1111")
{
         kkraj+='E';
ss="";
}
        
      }
      return kkraj;
  }
};