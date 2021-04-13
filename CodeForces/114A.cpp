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
    double n, x, y;
    cin >> n >> x >> y;
    double proc = (double)y / 100;
    double potr = (double)n*proc;
    double lujdze = potr - (double)x;
    if (lujdze <= 0.0) {
        cout << 0 << endl;
        return 0;
    }
    int broj = lujdze;
    double broj2 = broj;
    if (broj2 < lujdze) broj++;
    cout << broj << endl;



    return 0;
}