#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a = n/2;
        if (n % 2 == 0) a--;
        if (k > a) cout << -1 << endl;
        else {
            vector<int> v(n, 0);
            int br = 1;
            for (int i = n - k + 1; i <= n; i++) {
                v[br] = i;
                br += 2;
            }
            int bro = 1;
            for (int i = 0; i < n; i++) {
                if (!v[i]) v[i] = bro, bro++;
            }
            for (int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << endl;
        }
    }
    return 0;
}