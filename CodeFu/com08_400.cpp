#include <string>
#include <vector>
using namespace std;

class Playboy
{
  public:
    int noTomorrowWays(int N, int M)
    {
     vector<long long> dp(N+1,-1);
    dp[0]=1;
   dp[1]=0;
   for(long long i=2;i<=N;i++)
{
  dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
dp[i]%=M;
}
      return dp[N];
  }
};