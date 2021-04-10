#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n+=2;
        vector<int> v;
        ll zbir = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
            zbir += a;
        }
        sort(v.begin(), v.end());
        bool najde = false;
        for (int i = 0; i < n; i++) {
            if (najde) break;
            if (i != n - 1) {
                zbir -= v[i];
                zbir -= v[n - 1];
                if (zbir == v[n - 1]) {
                    for (int j = 0; j < n; j++) {
                        if (j == i || j == n - 1) continue;
                        cout << v[j] << " ";
                    }
                    cout << endl;
                    najde = true;
                    break;
                }
                zbir += v[n - 1];
                zbir += v[i];
            } else {
                zbir -= v[n - 1];
                zbir -= v[n - 2];
                if (zbir == v[n - 2]) {
                    for (int j = 0; j < n; j++) {
                        if (j == n - 2 || j == n - 1) continue;
                        cout << v[j] << " ";
                    }
                    cout << endl;
                    najde = true;
                    break;
                }
                zbir += v[n - 1];
                zbir += v[n - 2];
            }
        }
        if (!najde) cout << -1 << endl;
    }
    return 0;
}