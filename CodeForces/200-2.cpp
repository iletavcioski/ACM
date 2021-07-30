#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i <= a; i++) {
        int a1 = a;
        int b1 = b;
        int c1 = c;
        a1 -= i;
        if (b1 >= i) {
            b1 -= i;
            continue;
        }
        if (c1 >= a1 && a1 >= 0) {
            c1 -= a1;
            continue;
        }
        if (b1 >= c1 && c1 >= 0) {
            b1 -= c1;
            continue;
        }
        //cout << a1 << " " << b1 << " " << c1 << endl;
        if (b1 == 0) {
            cout << i << " " << c - a + i << " " << a - i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
