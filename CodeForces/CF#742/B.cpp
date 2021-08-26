#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

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
        string ss;
        cin >> ss;
        bool cc = false;
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] != '2' && ss[i] != '3' && ss[i] != '5' && ss[i] != '7') {
                //cout << "out" << endl;
                cout << 1 << endl;
                cout << ss[i] << endl;
                cc = true;
                break;
            }
        }
        if (cc) continue;
        for (int i = 0; i < ss.size(); i++) {
            for (int j = i + 1; j < ss.size(); j++) {
                int br = (ss[i] - '0') * 10 + (ss[j] - '0');
                if (br != 23 && br != 73 && br != 53 && br != 37) {
                    //cout << "out" << endl;
                    cout << 2 << endl;
                    cout << ss[i] << ss[j] << endl;
                    cc = true;
                    break;
                }
            }
        }
       

    }
    return 0;
}