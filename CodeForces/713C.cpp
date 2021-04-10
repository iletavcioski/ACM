#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') a--;
            else if (s[i] == '1') b--;
        }
        int i = 0;
        int j = s.size() - 1;
        bool nemozi = false;
        while (i <= j) {
                if (s[i] != '?' && s[j] == '?') {
                    if (s[i] == '0') s[j] = '0', a--;
                    if (s[i] == '1') s[j] = '1', b--;
                } else if (s[i] == '?' && s[j] != '?') {
                    if (s[j] == '0') s[i] = '0', a--;
                    if (s[j] == '1') s[i] = '1', b--;
                } else if (s[i] != '?' && s[j] != '?') {
                    if (s[i] != s[j]) nemozi = true;
                }
                if (a < 0 || b < 0) nemozi = true;
                i++;
                j--;
        }
        i = 0;
        j = s.size() - 1;
        while (i <= j) {
            if (s[i] == '?' && s[j] == '?') {
                int br= 2;
                if (i == j) br = 1;
                if (a >= b)
                    s[i] = '0', s[j] = '0', a-=br;
                else s[i] = '1', s[j] = '1', b-=br;
            }
            if (a < 0 || b < 0) nemozi = true;
            i++;
            j--;
        }

        if (nemozi) cout << -1 << endl;
        else {
            cout << s << endl;
        }
    }
    return 0;
}