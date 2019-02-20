#include <string>
#include <vector>
#include<cmath>
using namespace std;

class DiagonalCipher
{
  public:
    string encode(string message)
    {
int dol=message.size();
      int k=sqrt((double)dol);
     char mat[100][100];
int j=0;
for(int i=0;i<=100;i++)
{
   if(i*i==dol){
   k=i;break;}
else if(i*i>dol)
{k=i;break;}
}
int c=0;
    for(int i=0;i<k;i++)
   {
      for(int j=0;j<k;j++)
     {
    if(c<message.size()){
         mat[i][j]=message[c];
c++;}
else
mat[i][j]='*';
     }
   }
string ss="";

     for(int jj=k-1;jj>=0;jj--)
     {
         int i=k-1;
		 int j=jj;
         while(true)
         {
             ss+=mat[i][j];
if(i-1>=0&&j+1<k)
{
i-=1;
j+=1;
}
else
break;
          }
     }
 for(int ii=k-2;ii>=0;ii--)
     {
		 int i=ii;
         int j=0;
         while(true)
         {
             ss+=mat[i][j];
if(i-1>=0&&j+1<k)
{
i-=1;
j+=1;
}
else
break;
          }
     }
      return ss;
  }
};