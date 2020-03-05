#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    static int dp[102][102][105][2];
    int l;
	cin >> l;
	vector<int> v;
    vector<int> vis(l+ 1, 0);
    for (int i = 0; i < l; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        vis[a] = 1;
    }
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++)
            for (int k = 0; k < 105; k++)
                dp[i][j][k][0] = dp[i][j][k][1] = 1e9;
    int p = 0, n = 0;
    for (int i = 1; i <= l; i++) {
        if (vis[i] == 0) {
            if (i % 2)
                n++;
            else
                p++;
        }
    }
    //cout<<p<<" "<<n<<endl;
    if (v[0] == 0) {
        if (p)
        dp[0][p - 1][n][0] = 0;
        if (n)
        dp[0][p][n - 1][1] = 0;
    } else if (v[0] % 2) {
        dp[0][p][n][1] = 0;
    } else {
        dp[0][p][n][0] = 0;
    }
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j <= p; j++) {
            for (int k = 0; k <= n; k++) {
                for (int e = 0; e <= 1; e++) {
					if (v[i + 1] == 0) {
                    if (j)
                    dp[i + 1][j - 1][k][0] = min(dp[i + 1][j - 1][k][0], dp[i][j][k][e] + (e%2));
                    if (k)
                    dp[i + 1][j][k - 1][1] = min(dp[i + 1][j][k - 1][1], dp[i][j][k][e] + ((e + 1)%2));
					}
					else {
						dp[i + 1][j][k][v[i + 1] % 2] = min(dp[i][j][k][e] + ((e+v[i + 1])%2),dp[i+1][j][k][v[i+1]%2]);
					}
                }
            }
        }
    }
    int maxi = 1e9;
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= 1; k++) {
                maxi = min(maxi,dp[l - 1][i][j][k]);
            }
        }
    }
    cout<<maxi<<endl;
    return 0;
}