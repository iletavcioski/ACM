#include <string>
#include <vector>
#include<cstring>
using namespace std;

class MuffyAndTheGame
{
  public:
    int getMaximumPoints(vector<int> numbers, int n)
    {
    int po=0,ne=0;
for(int i=0;i<numbers.size();i++)
{
if(numbers[i]>0)
po++;
else
ne++;
}
bool kk=true;
long long res1=1;
int x=n;
int nn=ne; 
int pp=po;
while(x!=0)
{
if(kk)
{
res1*=po;
if(po!=0)
po--;
kk=false;
}
else
{
res1*=ne;
if(ne!=0)
ne--;
kk=true;
}
x--;
if(x==0)
break;
}
kk=true;
long long res2=1;
x=n;
while(x!=0)
{
if(kk)
{
res2*=nn;
if(nn!=0)
nn--;
kk=false;
}
else{
res2*=pp;
if(pp!=0)
pp--;
kk=true;
}
x--;
if(x==0)
break;
}
return res1+res2;
  }
};