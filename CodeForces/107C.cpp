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

    int n, q;
    cin >> n >> q;
    vector<int> v;
    vector<int> bo(51, -1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        if (bo[a] == -1) bo[a] = i + 1;
    }
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        cout << bo[a] << " ";
        for (int j = 1; j <= 50; j++) {
            if (j != a && bo[j] < bo[a]) {
                bo[j]++;
            }
        }
        bo[a] = 1;
    }
    cout << endl;

    return 0;
}