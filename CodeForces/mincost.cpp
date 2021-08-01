#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    string s = "";
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            s += ('a' + i);
            s += ('a' + j);
        }
    }
    string res = "";
    int i = 0;
    while (res.size() < n) {
        res += s[i];
        i++;
        if (i == s.size()) i = 0;
    }
    cout << res << endl;
    
    return 0;
}