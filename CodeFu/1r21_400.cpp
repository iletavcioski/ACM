#include <string>
#include <vector>
using namespace std;

class Marker
{
  public:
    int bestMarking(vector<int> a, int n, int k)
    {
        int dp[101][101];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {

                    dp[i][j]= -1e9;

            }
        }
        dp[0][0] = a[0];
        dp[0][1] = -a[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                int momzn = 1;
                if (j % 2 == 1) momzn = -1;
                int slzn = 1;
                if (momzn == 1) slzn = -1;

                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + momzn * a[i]);
                        if (j < k)
                            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + slzn * a[i]);
            }
        }
       
        return dp[n - 1][k];
    }
};