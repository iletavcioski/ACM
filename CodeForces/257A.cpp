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
    int n, m;
    cin >> n >> m;
    queue<pair<int,int> > qi;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        qi.push(make_pair(a, i + 1));
    }
    int posl = 0;
    while (!qi.empty()) {
        pair<int,int> a = qi.front();
        qi.pop();
        posl = a.s;
        a.f -= m;
        if (a.f > 0) {
            qi.push(a);
        }
    }
    cout << posl << endl;


    return 0;
}