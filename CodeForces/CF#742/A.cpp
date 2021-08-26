#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int a = r;
        int b = max(a / 2 + 1, l);
        cout << a % b << endl;
    }
    return 0;
}