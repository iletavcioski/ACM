#include <string>
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;

class ResistorRead
{
  public:
    string getOhms(string colorBands)
    {
         string mnozac="";
           int k=0;
      for(int i=colorBands.size()-1;i>=0;i--){
      if(colorBands[i]!=' ')
      mnozac+=colorBands[i];
else
{
k=i;
break;

}
}
reverse(mnozac.begin(),mnozac.end());
int mno;
if(mnozac=="violet")
mno=10000000;
else if(mnozac=="black")
mno=1;
else if(mnozac=="brown")
mno=10;
else if(mnozac=="red")
mno=100;
else if(mnozac=="orange")
mno=1000;
else if(mnozac=="yellow")
mno=10000;
else if(mnozac=="green")
mno=100000;
else if(mnozac=="blue")
mno=1000000;
 vector<int> v;
string ss="";
for(int i=0;i<=k;i++)
{
  if(colorBands[i]!=' ')
{
ss+=colorBands[i];
}
else
{
  if(ss=="violet")
v.push_back(7);
else if(ss=="black")
v.push_back(0);
else if(ss=="brown")
v.push_back(1);
else if(ss=="red")
v.push_back(2);
else if(ss=="orange")
v.push_back(3);
else if(ss=="yellow")
v.push_back(4);
else if(ss=="green")
v.push_back(5);
else if(ss=="blue")
v.push_back(6);
else if(ss=="gray")
v.push_back(8);
else if(ss=="white")
v.push_back(9);
ss="";
}
}
 
long long kraj=0;
for(int i=v.size()-1;i>=0;i--)
{
  double kk=v.size()-i-1;
  double broj=v[i]*pow(10,kk);
kraj+=broj;
}
kraj*=mno;
string kkraj;
while(kraj>0)
{
  char b=kraj%10;
  kkraj+=b+'0';
kraj/=10;
}
reverse(kkraj.begin(),kkraj.end());
kkraj+=" ohms";


      return kkraj;
  }
};