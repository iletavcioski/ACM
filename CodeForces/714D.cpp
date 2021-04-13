#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <stack>

#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;
typedef long long ll;

struct izbor {
    int val;
    int idx;
};

bool const operator <(const izbor &x, const izbor &y) {
    if(x.val>y.val)
        return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        priority_queue<izbor> pq;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
            pq.push({a, i});
        }
        vector<int> vis(n, 0);
        ll brojac = 0;
        while (!pq.empty()) {
            izbor g = pq.top();
            //cout << g.val << endl;
            pq.pop();
            if (g.val >= k) continue;
            if (vis[g.idx]) continue;
            for (int i = g.idx; i < n - 1; i++) {
                if (v[i + 1] % g.val == 0 && !vis[i]) {
                    vis[i] = true;
                    brojac += (ll) g.val;
                } else {
                    break;
                }
            }

            for (int i = g.idx; i > 0; i--) {
                if (v[i - 1] % g.val == 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    brojac += (ll) g.val;
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (!vis[i])
                brojac += k;
        }
        cout << brojac << endl;

    }

    return 0;
}