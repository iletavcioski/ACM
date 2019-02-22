#include <string>
#include <vector>
#include<cstring>
using namespace std;

class CoinsKeeper
{
  public:
    int solve(int X, int Y, int Z, int P)
    {
       
               int dp[8001];
        memset(dp,0,sizeof(dp));
        dp[X+Y*2+Z*5]=X+Y+Z;
         int dp1[8000],dp2[8000],dp3[8000];
memset(dp1,-1,sizeof(dp1));
memset(dp2,-1,sizeof(dp2));
memset(dp3,-1,sizeof(dp3));
   dp[0]=X+Y+Z;
      dp1[0]=X;
       dp2[0]=Y;
        dp3[0]=Z;

		int zbir=X+Y*2+Z*5;

        for(int i=0;i<=zbir;i++)
        {
           if(dp[i]!=0)
            {
                  if(i+1<=zbir&&dp1[i]>0&&dp[i+1]<=dp[i]-1)
                  {
					dp[i+1]=dp[i]-1;
                   dp1[i+1]=dp1[i]-1;
                     dp2[i+1]=dp2[i];
                   dp3[i+1]=dp3[i];
				}
				

                   if(dp2[i]>0&&i+2<=zbir&&dp[i+2]<=dp[i]-1)
                        {
	     
                  dp[i+2]=dp[i]-1;
                dp2[i+2]=dp2[i]-1;
                    dp1[i+2]=dp1[i];
                 dp3[i+2]=dp3[i];
                         }
                   if(dp3[i]>0&&i+5<=zbir&&dp[i+5]<=dp[i]-1)
                      {
                  dp[i+5]=dp[i]-1;
                   dp3[i+5]=dp3[i]-1;
				   dp1[i+5]=dp1[i];
				   dp2[i+5]=dp2[i];
                      }
            }
        }

return dp[P];
}
};