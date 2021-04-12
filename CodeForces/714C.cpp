#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll fact[250001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll broj = 1;
    fact[0] = broj;
    fact[1] = broj;
    for (int i = 2; i <= 250000; i++) {
        broj *= i;
        broj %= mod;
        fact[i] = broj;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxx = 0;
        int a = 1000000000;
        while (a > 0) {
            a /= 2;
            maxx++;
        }
        vector<int> pos(maxx + 1, 1);
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int br;
            cin >> br;
            v.push_back(br);
            if (br == 0) {
                for (int j = 1; j <= maxx; j++) pos[j] = 0;
            }
            int kr = maxx;
            while (br > 0) {
                int brk = br % 2;
                pos[kr] &= brk;
                kr--;
                br /= 2;
            }
            for (int j = kr; j >= 1; j--) pos[j] &= 0;
        }
        ll mn = 1;
        ll broj = 0;
        for (int i = maxx; i >= 1; i--) {
            if (pos[i] == 1) broj += mn;
            mn*=2;
        }
        ll brojac = 0;
        for (int i = 0; i < n; i++) {
            if (broj == v[i])
                brojac++;
        }
        ll br1 = brojac;
        ll br2 = brojac - (ll)1;
        ll res = br1 * br2;
        res /= (ll)2;
        res %= mod;
        res *= 2;
        res %= mod;
        res *= fact[n - 2];
        res %= mod;
        cout << res << endl;
    }
    return 0;
}