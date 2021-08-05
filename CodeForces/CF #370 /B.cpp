#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    string ss;
    cin >> ss;

    int niz[4];
    niz[0] = niz[1] = niz[2] = niz[3] = 0;

    for (int i = 0; i < ss.size(); i++) {
        if (ss[i] == 'L') niz[0]++;
        if (ss[i] == 'R') niz[1]++;
        if (ss[i] == 'U') niz[2]++;
        if (ss[i] == 'D') niz[3]++;
    }

    if (ss.size() % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    int mini = 1e9;
    for (int i = 0; i < ss.size() / 2; i++) {
        int j = ss.size() / 2 - i;
        mini = min(mini, min((abs(niz[0] - i) + abs(niz[1] - i) + abs(niz[2] - j) + abs(niz[3] - j)) / 2, (abs(niz[0] - j) + abs(niz[1] - j) + abs(niz[2] - i) + abs(niz[3] - i)) / 2));
    }
    cout << mini << endl;
    return 0;
}