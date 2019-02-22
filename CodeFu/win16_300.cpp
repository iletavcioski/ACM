#include <string>
#include <vector>
#include<cmath>
using namespace std;

class Serpent
{
  public:
    int findNumber(int n, int r, int c)
    {
      int ii=0;
int jj=0;
long long brojac=1;
int bb=1;
 int bbb=3;
int gore=1;
while(true)
{
if(ii==r&&jj==c)
return brojac;
   if(bb==1)
{
if(ii==r&&c>=jj)
return brojac+c-jj;
}
if(bb==2)
{
if(jj==c&&r>=ii)
return brojac+r-ii;
}
if(bb==3)
{
if(ii==r&&jj>=c)
return brojac+jj-c;
}
if(bb==4)
{
if(jj==c&&ii>=r)
return brojac+ii-r;
}


    if(bb==1) 
   {
   jj+=n-1;
   bb=2;
   bbb--;
   brojac+=n-1;
gore=1;
  }
else if(bb==2)
{
  ii+=n-1;
  bb=3;
  bbb--;
brojac+=n-1;
gore=1;
}
else if(bb==3)
{
   jj-=n-1;
   bb=4;
bbb--;
brojac+=n-1;
gore=2;
}
else if(bb==4)
{
  ii-=n-1;
brojac+=n-1;
  bb=1;
bbb--;
gore=2;
}
if(bbb==0){
n--;
bbb=2;
}
    
    
}
      return 0;
  }
};