#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                v.push_back(i);
        }
        ll brojac = 0;
        ll mini = 1e18;
        int m = v.size();
        deque<int> desno;
        vector<int> raz;
        for (int i = 0; i < n - 1; i++) 
            raz.push_back(v[i + 1] - v[i]);
        deque<int> levo;
        deque<int> sred;
        ll des = 0;
        ll sre = 0;
        ll lev = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= m) desno.push_back(v[i]);
        }
        ll mn = 1;
        for (int i = raz.size() - 1; i > raz.size() - desno.size(); i--) {
            des += mn * raz[i];
            mn++;
        }
        int l = 0, r = m - 1;
        int lbr = 0;
        int sbr = m - desno.size();
        int dbr = desno.size();
        mn = 1;
        for (int i = raz.size())
        while (r < n) {
            if (sred[0] > l) {
                levo.push_back(sred[0]);
                sred.pop_front();
            } else if (desno[0] <= r) {
                sred.push_back(desno[0]);
                desno.pop_front();
            }
        }


    }
    return 0;
}

/*
0 0 -1, 1 1 0, 2 2 1, 3 3 2, 4 4 3, 5 5 4,
*/