#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll mod = 1000000007;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a;
        cin >> a;
        ll res = 0;
        ll odd = a / 2;

        if (a % 2)
            odd++, a--;
        
        res += (odd * 2);
        res %= mod;

        ll div3 = a / 4;
        ll div4 = a / 4;

        if (a % 4) div3++;
        res += (div3 * 4);
        res %= mod;

        res += (div4 * 5);
        res %= mod;
        cout << res << endl;
    }
    return 0;
}