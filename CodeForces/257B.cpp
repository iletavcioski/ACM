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

const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    ll x, y;
    cin >> x >> y;
    ll n;
    cin >> n;
    ll c = y - x;
    if (n % (ll)3 == (ll)0) {
        n /= (ll)3;
        ll broj = c;
        if (n % (ll)2 == (ll)0) broj *= (ll)-1;
        while (broj < 0) broj += mod;  
        broj %= mod;
        cout << broj << endl;
    }
    else if (n % (ll)3 == (ll)1) {
        n /= (ll)3;
        ll broj = x;
        if (n % (ll)2) broj *= (ll)-1;
        while (broj < (ll)0) broj += mod;
        broj %= mod;  
        cout << broj << endl;
    }
    else if (n % (ll)3 == (ll)2) {
        n /= (ll)3;
        ll broj = y;
        if (n % (ll)2) broj *= (ll)-1;
        while (broj < (ll)0) broj += mod;
        broj %= mod;
        cout << broj << endl;
    }

    return 0;
}