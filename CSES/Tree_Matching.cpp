#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int> > v;
int dp[200002][2];

void dfs(int prev, int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (prev != v[x][i]) {
            dfs(x, v[x][i]);
        }
    }

    for (int i = 0; i < v[x].size(); i++) {
        if (prev != v[x][i]) {
            dp[x][0] += max(dp[v[x][i]][0], dp[v[x][i]][1]); 
        }
    }

    for (int i = 0; i < v[x].size(); i++) {
        if (prev != v[x][i]) {
            dp[x][1] = max(dp[x][1],dp[x][0] -  max(dp[v[x][i]][0], dp[v[x][i]][1]) + dp[v[x][i]][0] + 1); 
        }
    }
}
int main() {
    int n;
    cin >> n;
    
    vector<int> vec;
    v.insert(v.begin(), n + 1, vec);
    vector<int> cnt(n, 0);
    vector<int> vis(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(-1, 0);
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}