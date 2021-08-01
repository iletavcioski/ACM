#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

vector<ll> vv;
ll st[1000000];

void build(int l, int r, int p) {
    st[p] = 0;
    if (l == r) {
        st[p] = vv[l];
        return;
    }

    build(l ,(l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);
    st[p] = gcd(st[2 * p], st[2 * p + 1]);
    return;

}
int I, J;

ll qu(int l, int r, int p) {
    if (l >= I && r <= J) {
        return st[p];
    }
    if (l > J || r < I)
    {
        return 0;
    }
    return gcd(qu(l, (l + r) / 2, 2*p), qu((l + r) / 2 + 1, r, 2 * p + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) {
        vv.clear();
        int n;
        cin >> n;
        vector<ll> v;
        for (int i = 0; i < 4 * n; i++) st[i] = 0;
        int mini = 0;

        ll prgcd;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            v.pb(a);
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            vv.pb(abs(v[i + 1] - v[i]));
        }

        n--;
        build(0, n - 1, 1);
        I = 0;
        J = 0;
        while (I < n && J < n) {
            if (I < n && J < n && qu(0, n - 1, 1) > 1) {
                mini = max(mini, J - I + 1);
            }
            J++;
            while (I < n && J < n && I < J && qu(0, n - 1, 1) == 1) {
                I++;
            }
            if (I < n && J < n && qu(0, n - 1, 1) > 1) {
                mini = max(mini, J - I + 1);
            }

        }

        cout << mini + 1 << endl;
    }

    return 0;
}

/*
4
15
1 4 2 8 7 5 9 15 6 12 14 10 11 3 13
18
9 14 3 10 11 6 12 8 1 18 15 4 16 17 13 7 5 2
1
1
16
13 5 10 16 8 11 7 14 1 2 4 3 15 6 12 9
*/