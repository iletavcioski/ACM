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
    vector<ll> v;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.pb(a);
    }
    
    for (int i = 0; i < n - 1; i++) {
        cout << v[i] + v[i + 1] << " ";
    }
    cout << v[n - 1] << endl;
    return 0;
}