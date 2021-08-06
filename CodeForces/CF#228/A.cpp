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

    int n;
    cin >> n;
    
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.pb(a);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        bool cc = true;
        vector<int> vis(i, 1e9);
        for (int j = 0; j < n; j++) {
            int maxi = 0;
            int which = -1;
            for (int k = 0; k < i; k++) {
                if (vis[k] > maxi) {
                    maxi = vis[k];
                    which = k;
                }
            }
            if (which == -1) {
                cc = false;
                break;
            }
            vis[which] = min(vis[which] - 1, v[j]);
        }
        if (cc) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}