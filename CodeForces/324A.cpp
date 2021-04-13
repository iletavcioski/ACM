#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <stack>

#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;
typedef long long ll;

int len(ll a) {
    int br = 0;
    if (a == 0) return 1;
    while (a > 0) {
        a /= 10;
        br++;
    }
    return br;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    ll n, t;
    cin >> n >> t;
    string ss;
    if (t >= 2 && t <= 9) ss = t + '0';
    if (t == 10) ss += "10";
    while (ss.size() < n) ss += '0'; 
    if (ss.size() != n) cout << -1 << endl;
    else cout << ss << endl;
    
    return 0;
}