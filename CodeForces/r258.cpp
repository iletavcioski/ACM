#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        ll br = n - k;
        ll brojac = 0;
        brojac = d1 + d1 + d2;
        if (br > brojac) br -= brojac;
        else br = -1;
        if (br % 3 == 0 && br >= 0) 
            cout << "yes" << endl;
        else
            cout << "no" << endl; 
    }
    return 0;
}