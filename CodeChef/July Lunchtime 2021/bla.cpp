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
        int n, d, h;
        cin >> n >> d >> h;
        int br = 0;
        bool cc = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a > 0) br += a;
            else if (a == 0) br = max(br - d, 0);
            if (br > h) {
                cc = true;
            }
        }
        if (cc) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}