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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int u1 = 0, d1 = 0, u2 = 0, d2 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1 || a == 3) u1++;
        }
        cout << u1 + u2 << endl;
    }
    return 0;
}