#include <string>
#include <vector>
using namespace std;
typedef long long ll;
class IpAddresses
{
  public:

    int count(string S, int K)
    {
const ll mod=1000000007;
       ll dp[102][102];
       for(int i=0;i<=101;i++)
{
   for(int j=0;j<=101;j++)
{
dp[i][j]=0;
}
}
	   dp[0][0]=1;
  
for(int j=1;j<=K;j++)
{
       for(int i=1;i<=S.size();i++)
{
   

         int broj1=-1;
         int broj2=-1;
         int broj3=-1;
         if(i>=1)
          broj1=S[i-1]-'0';
         if(i>=2&&S[i-2]!='0')
          broj2=(S[i-2]-'0')*10+(S[i-1]-'0');
if(i>=3&&S[i-3]!='0')
broj3=(S[i-3]-'0')*100+(S[i-2]-'0')*10+(S[i-1]-'0');
if(broj3>255)
broj3=-1;
if(broj1!=-1)
{
   dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
dp[i][j]%=mod;
}
if(broj2!=-1)
{
   dp[i][j]=(dp[i][j]+dp[i-2][j-1])%mod;
dp[i][j]%=mod;
}
if(broj3!=-1)
{
   dp[i][j]=(dp[i][j]+dp[i-3][j-1])%mod;
dp[i][j]%=mod;
}
         
     }
}
int brojac=(int)dp[S.size()][K];
return brojac;
  }
};