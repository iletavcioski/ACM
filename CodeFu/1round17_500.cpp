#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class SecretNumbers
{
public:
    const ll mod = 1000000007;
    ll dp[901][2];
    ll d[10][101];
    int f(int p, int n, int k, ll poc) {
        for (int i = 0; i <= k; i++) {
            dp[i][0] = -1;
            dp[i][1] = 0;
        }
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = p; i < n; i++) {
            int br = 9;
            for (int l = k; l >= 0; l--) {
                for (int j = br; j >= 1; j--){
                    if (dp[l][0] != -1 && l + j <= k) {
                        if (dp[l + j][0] == -1) {
                            dp[l + j][0] = 0;
                        }

                        dp[l + j][0] = (dp[l + j][0] + (dp[l][0] + ((dp[l][1] * d[j][n - i - 1]) % mod))%mod) % mod;
                        //dp[l + j][0] %= mod;
                        dp[l + j][1] = (dp[l + j][1] + dp[l][1])%mod;

                    }
                }
            }
        }
        if (dp[k][0] == -1)
            return 0;
        return ((dp[k][0] + (dp[k][1]*poc)%mod)%mod);
    }
    ll findSum(string N, int K)
    {
        for (int i = 0; i <= 9; i++) {
            ll br = i;
            d[i][0] = br;
            for (int j = 1; j <= 100; j++) {
                br = (br * 10)%mod;
                // br %= mod;
                d[i][j] = br;
            }
        }
        ll counter = 0;
        int n = N.size();
        int br = 0;
        ll poc = 0;
        for (int i = 0; i < N.size(); i++) {
            n--;
            for (int j = N[i] - '0' - 1; j >= 0; j--) {
                br += j;
                if (br > K) {
                    br -= j;
                    continue;
                }
                if (br == K) {
                    counter = (counter + (poc + d[j][n])%mod)%mod;
                    //counter %= mod;
                    br -= j;
                    continue;
                }
                ll poc1 = poc;
                poc = (poc + d[j][n]) % mod;
                //poc %= mod;
                counter = (counter + f(0, n, K - br, poc)) % mod;
                //counter %= mod;
                poc = poc1;
                br -= j;
            }
            br += N[i] - '0';
            poc = (poc + d[N[i] - '0'][n]) % mod;

        }
        if (br == K) {
            counter = (counter + poc) % mod;

        }

        return (counter % mod);
    }
};


