#include <bits/stdc++.h>

#define pb push_back

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v;
        map<ll, int> vis;
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            v.pb(a);
        }
        ll all = (n * (ll)(n - 1LL));
        //cout << all << endl;
        ll brojac = 0;
        for (ll i = 0; i < n; i++) {
            brojac += (ll)(vis[v[i]] * 2LL);
            vis[v[i]]++;
        }
        cout << (ll)(all - brojac) << endl;
    }
    return 0;
}