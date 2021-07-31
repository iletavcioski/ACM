#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define pb push_back

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int dp[n + 1][3];
    dp[0][0] = (s[0] == 'a');
    dp[0][1] = (s[0] == 'b');
    dp[0][2] = (s[0] == 'c');
    for (int i = 3; i < n; i += 3) {
        dp[i][0] = dp[i - 3][0] + (s[i] == 'a');
        dp[i][1] = dp[i - 3][1] + (s[i] == 'b');
        dp[i][2] = dp[i - 3][2] + (s[i] == 'c');
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int mat[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = 0;
            }
        }

        int len = b - a + 1;
        if (len % 3 == 0) {
            for (int j = 0; j < 3; j++) {
                mat[0][j] = dp[b - 2][j];
                if (a - 3 >= 0) 
                    mat[0][j] -= dp[a - 3][j];
            }

            for (int j = 0; j < 3; j++) {
                mat[1][j] = dp[b - 1][j];
                if (a - 2 >= 0) 
                    mat[1][j] -= dp[a - 2][j];
            }
            for (int j = 0; j < 3; j++) {
                mat[2][j] = dp[b][j];
                if (a - 1 >= 0) 
                    mat[2][j] -= dp[a - 1][j];
            }
        } else if (len % 3 == 1) {
            for (int j = 0; j < 3; j++) {
                mat[0][j] = dp[b][j];
                if (a - 3 >= 0) 
                    mat[0][j] -= dp[a - 3][j];
            }

            for (int j = 0; j < 3; j++) {
                mat[1][j] = dp[b - 2][j];
                if (a - 2 >= 0) 
                    mat[1][j] -= dp[a - 2][j];
            }
            for (int j = 0; j < 3; j++) {
                mat[2][j] = dp[b - 1][j];
                if (a - 1 >= 0) 
                    mat[2][j] -= dp[a - 1][j];
            }
        } else if (len % 2 == 2) {
            for (int j = 0; j < 3; j++) {
                mat[0][j] = dp[b - 1][j];
                if (a - 3 >= 0) 
                    mat[0][j] -= dp[a - 3][j];
            }

            for (int j = 0; j < 3; j++) {
                mat[1][j] = dp[b][j];
                if (a - 2 >= 0) 
                    mat[1][j] -= dp[a - 2][j];
            }
            for (int j = 0; j < 3; j++) {
                mat[2][j] = dp[b - 2][j];
                if (a - 1 >= 0) 
                    mat[2][j] -= dp[a - 1][j];
            }
        }

        int maxi = 0;
        vector<int> ve;
        ve.pb(0);
        ve.pb(1);
        ve.pb(2);
        do{
            int brojac = 0;
            for (int j = 0; j < 3; j++) {
                brojac += mat[j][ve[j]];
            }
            maxi = max(maxi, brojac);
        }while(next_permutation(ve.begin(), ve.end()));
        cout << len - maxi << endl;
    }
}