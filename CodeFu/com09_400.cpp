#include <string>
#include <vector>
#include<cstring>
using namespace std;

class Bouquets
{
  public:
    int happiness(vector<int> flowers)
    {
     bool dp[2501];
memset(dp,false,sizeof(dp));
dp[0]=true;
int n=flowers.size();
      for(int i=0;i<n;i++)
{ 
         for(int j=2500;j>=0;j--)
{
             if(dp[j]&&j+flowers[i]<=2500)
                  dp[j+flowers[i]]=true;    
}   
 }
  int res=0;
for(int i=0;i<=2500;i++)
if(dp[i])
res++;
      return res-1;
  }
};