#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<vector<int> > v;
ll dp[200002][2];
ll dp1[200002];
ll dp2[200002];
void dfs(int p, int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (p != v[x][i]) {
            dfs(x, v[x][i]);
            dp1[x] += 1LL + dp1[v[x][i]];
        }
    }
}
void dfs1(int p, int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (p != v[x][i]) {
            dfs1(x, v[x][i]);
            dp[x][0] += dp[v[x][i]][0] + dp1[v[x][i]] + 1LL;
        }
    }
}

void dfs2(int p, int x, ll pat, ll vleci) {
    dp[x][1] = pat;
    if (x == 0) {
        for (int i = 0; i < v[x].size(); i++) {
            if (p != v[x][i]) {
                dfs2(x, v[x][i], dp[x][0] - dp[v[x][i]][0] - dp1[v[x][i]] - 1LL + (dp1[x] - dp1[v[x][i]]), vleci + (dp1[x] - dp1[v[x][i]]));
            }
        }
        return;
    }

    for (int i = 0; i < v[x].size(); i++) {
        if (p != v[x][i]) {
            dfs2(x, v[x][i], pat + (dp[x][0] - dp[v[x][i]][0] - dp1[v[x][i]] - 1LL) + (dp1[x] - dp1[v[x][i]]) + vleci, vleci + (dp1[x] - dp1[v[x][i]]));
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> vec;
    v.insert(v.begin(), n + 1, vec);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(-1, 0);
    dfs1(-1, 0);
    dfs2(-1, 0, 0, 0);
    /*
    for (int i = 0; i < n; i++) {
        cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][0] + dp[i][1] << endl;
    }
     */
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << dp[i][0] + dp[i][1];
    }
    cout << endl;
    return 0;
}