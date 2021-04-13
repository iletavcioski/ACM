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

    int n, k;
    cin >> n >> k;
    string s = "";
    string s1 = "";
    for (int i = 1; i <= k; i++) {
        s1 += ('a' + i - 1);
        for (int j = i + 1; j <= k; j++) {
            s1 += ('a' + i - 1);
            s1 += ('a' + j - 1);
        }
    }
    int i = 0;
    while (s.size() < n) {
        s += s1[i];
        i++;
        if (i == s1.size()) i = 0;
    }
    cout << s << endl;

    return 0;
}