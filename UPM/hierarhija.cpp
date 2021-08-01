#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define s second
#define f first

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, d, k;
    cin >> n >> d >> k;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.pb(a);
    }
    ll res = 0;
    while (k--) {
        ll maxi = -1;
        int pos = -1;
        vector<ll> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + v[i];
        }
        for (int i = 1; i <= n; i++) {
            if (i + d - 1 <= n && dp[i + d - 1] - dp[i - 1] > maxi) {
                maxi = dp[i + d - 1] - dp[i - 1];
                pos = i;
            }
        }
        
        for (int i = pos; i <= pos + d - 1; i++) {
            v[i] = 0;
        }
        res += maxi;
    }
    cout << res << endl;
    return 0;
}