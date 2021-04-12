#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll dp[250010];
ll mom[10];
ll mom2[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

        for (int k = 0; k <= 9; k++) {
            mom[k] = 0;
            mom2[k] = 0;
        }
        int i = 0;
        mom[i] = 1;
        dp[0] = 1;
        for (int j = 1; j <= 250009; j++) {
            for (int k = 0; k <= 9; k++) {
                if (mom[k] && k != 9) mom2[k + 1] += mom[k], mom2[k + 1] %= mod;
                if (mom[k] && k == 9) mom2[1] += mom[k], mom2[0] += mom[k], mom2[1] %= mod, mom2[0] %= mod;
            }
            ll brojc = 0;
            for (int k = 0; k <= 9; k++) {
                brojc += mom2[k];
                brojc %= mod;
                dp[j] = brojc;
                mom[k] = mom2[k];
                mom2[k] = 0;
            }
        }
    int t;
    cin >> t;
    while (t--) {
        string n;
        int k;
        cin >> n >> k;
        ll brojac = 0;
        for (int i = 0; i < n.size(); i++) {
            //cout << n[i] << " " << k << endl;
            //cout << dp[n[i]-'0'][k] << endl;
            brojac += dp[(int)(n[i]-'0') + k];
            brojac %= mod;
        }
        cout << brojac << endl;
    }
    return 0;
}