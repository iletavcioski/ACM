#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;
vector<int> dp(1000001, 0);
int dfs(int prev, int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (prev != v[x][i])
            dp[x] += 1 + dfs(x, v[x][i]);
    }
    return dp[x];
}
int main() {
    int n;
    cin >> n;
    vector<int> vec;
    v.insert(v.begin(), n + 1, vec);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        v[a].push_back(i);
        v[i].push_back(a);
    }
    dfs(-1, 0);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << dp[i];
    }
    cout << endl;
    return 0;
}