#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
    ll a, b, n;
    cin >> a >> b >> n;

    for (int i = 0; i < n; i++) {

        ll maxi = -1;
        ll l, t, m;
        cin >> l >> t >> m;
        ll r = 1e9;
        ll l1 = l;
        while (l1 <= r) {
            ll mid = (l1 + r) / 2;
            ll br1 = max((l-1)*a + b*(((l - 2) * (l-1))/2),0*1LL);
            ll k = max((mid - m + 1),l);
            ll br2 = mid*a + ((mid - 1)*mid)/2 * b;
            ll br = br2 - br1;
            ll maks = a + (mid - 1)*b;
            if (maks <= t && br <= m*t) {
                l1 = mid + 1;
                maxi = max(maxi, mid);
            }
            else
            {
                r = mid - 1;
            }

        }
        cout << maxi << endl;
    }

    return 0;
}
