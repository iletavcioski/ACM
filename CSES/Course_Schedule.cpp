#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > v;
vector<bool> vis(1000001, 0);
bool have_cycle = false;
void dfs(int poc, int x) {
    if (poc == x && vis[x]) {
        have_cycle = true;
        return;
    }
    if (vis[x]) return;
    vis[x] = true;
    for (int i = 0; i < v[x].size(); i++) {
        dfs(poc, v[x][i]);
    }
}
void print_vector(vector<int> vv) {
    for (int i = 0; i < vv.size(); i++) {
        if (i)
            cout << " ";
        cout << vv[i] + 1;
    }
    cout << endl;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vec;
    v.insert(v.begin(), n + 1, vec);
    vector<int> in_degree(n + 1, 0);
    queue<int> q;
    vector<int> l;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        in_degree[b]++;
        v[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i, i);
    }

    if (have_cycle) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!in_degree[i])
            q.push(i);
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        l.push_back(top);
        for (int i = 0; i < v[top].size(); i++) {
            in_degree[v[top][i]]--;
            if (!in_degree[v[top][i]])
                q.push(v[top][i]);
        }
    }

    print_vector(l);
    return 0;
}