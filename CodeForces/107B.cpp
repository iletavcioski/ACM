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
int len(ll a) {
    int br = 0;
    if (a == 0) return 1;
    while (a > 0) {
        a/=10;
        br++;
    }
    return br;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        //int u1 = 0, d1 = 0, u2 = 0, d2 = 0;
        vector<ll> vec(10, 0);
        vec[1] = 1;
        for (int i = 2; i <= 9; i++) {
            vec[i] = 10*vec[i-1];
        }
        ll a1 = vec[c];
        ll b1 = vec[c];
        ll c1 = vec[c];
        while (len(a1) < a) a1*=2;
        while (len(b1) < b) b1*=3;
        cout << a1 << " " << b1 << endl;
    }
    return 0;
}