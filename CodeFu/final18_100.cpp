#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Darts
{
  public:
    string finalResult(vector<int> playerA, vector<int> playerB)
    {
    vector<int> v,g;
v=playerA;
g=playerB;
    int br=301;
        int br1=301;
    for(int i=0;i<v.size();i+=3)
    {
int a=br,b=br1;
    for(int j=i;j<i+3;j++){
        if(br-v[j]>=0){
        br-=v[j];}
else
{
br=a;
break;
}
if(br==0)
break;
}
        if(br==0)
            break;
for(int j=i;j<i+3;j++){
        if(br1-g[j]>=0){
            br1-=g[j];}
else
{
br1=b;
break;
}
            if(br1==0)
            break;
}
if(br1==0)
break;
    }
    string s1="";
    string s2="";
    if(br==0)
        s1="0";
    while(br>0)
    {
        s1+=((br%10)+'0');
        br/=10;
    }
    if(br1==0)
        s2="0";
    while(br1>0)
    {
        s2+=((br1%10)+'0');
        br1/=10;
    }
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
    return (s1+":"+s2);
  }
};