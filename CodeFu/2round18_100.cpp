#include <string>
#include <vector>
#include <map>
using namespace std;

class MorseCode
{
  public:
    string decode(string morseCode)
    {
    map<string,int> m;
    m["-----"]=0;
    m[".----"]=1;
    m["..---"]=2;
    m["...--"]=3;
    m["....-"]=4;
    m["....."]=5;
    m["-...."]=6;
    m["--..."]=7;
    m["---.."]=8;
    m["----."]=9;
    int br=0;
    string s1="";
    string kraj="";
    for(int i=0;i<morseCode.size();i++)
    {
        s1+=morseCode[i];
        br++;
        if(br==5)
        {
            kraj+=(m[s1]+'0');
            br=0;
            s1="";
        }
    }
    return kraj;
  }
};