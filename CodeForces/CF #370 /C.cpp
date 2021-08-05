#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int x, y;
    cin >> x >> y;

    vector<int> v;
    v.pb(y);
    v.pb(y);
    v.pb(y);

    int brojac = 0;

    while (v[0] != x || v[1] != x || v[2] != x) {
        v[0] = v[1] + v[2] - 1;
        if (v[0] > x) v[0] = x;
        sort(v.begin(), v.end());
        brojac++;
    }
    cout << brojac << endl;
    return 0;
}