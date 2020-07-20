#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
struct node
{
    int x;
    int posl;
    int in;
    ll dist;
};
const bool operator<(const node &x,const node &y)
{
    if (x.dist > y.dist) return true;
    else if (x.dist < y.dist) return false;
    else {
        return x.posl > y.posl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<bool> vis(n + 1, false);
    priority_queue<node> pq;
    vector<vector<pair<int,pair<int,int> > > > v;
    vector<pair<int,pair<int,int> > > vec;
    v.insert(v.begin(), n + 1, vec);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        v[a].push_back(make_pair(c,make_pair(b,i)));
        v[b].push_back(make_pair(c,make_pair(a,i)));
    }
    int u;
    cin >> u;
    u--;
    node g;
    g.x = u;
    g.dist = 0;
    g.posl = -1;
    g.in = -1;
    pq.push(g);
    vector<int> vv;
    ll brojac = 0;
    while (!pq.empty()) {
        g = pq.top();
        pq.pop();
        //cout<< g.x << endl;
        if (vis[g.x]) continue;
        vis[g.x] = true;
        if (g.in != -1) {
        vv.push_back(g.in);
        brojac += g.posl;
        }
        for (int i = 0; i < v[g.x].size(); i++) {
            node g1;
            g1.x = v[g.x][i].second.first;
            g1.posl = v[g.x][i].first;
            g1.dist = v[g.x][i].first + g.dist;
            g1.in = v[g.x][i].second.second;
            pq.push(g1);
        }
    }
    cout << brojac << endl;
    for (int i = 0; i < vv.size(); i++) {
        if (i) cout << " ";
        cout << vv[i] + 1;
    }
    cout << endl;
    return 0;
}