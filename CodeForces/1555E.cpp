#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

int I, J, value;
int st[4000000];
int lazy[4000000];

void up(int l, int r, int p) {

    if (lazy[p] != 0) {
        st[p] += lazy[p];
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if (l >= I && r <= J) {
        st[p] +=  value;
        if (l != r) {
            lazy[2 * p] += value;
            lazy[2 * p + 1] += value;
        }
        return;
    }



    if (l > J || r < I) {
        return;
    }


    up(l, (l + r) / 2, 2 * p);
    up((l + r) / 2 + 1, r, 2 * p + 1);

    st[p] = min(st[2 * p], st[2 * p + 1]);
    return;
}

int query(int l, int r, int p) {
    if (lazy[p] != 0) {
        st[p] += lazy[p];
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if (l >= I && r <= J) {
        return st[p];
    }

    if (l > J || r < I) {
        return 1e9;
    }
    query(l, (l + r) / 2, 2 * p);
    query((l + r) / 2 + 1, r, 2 * p + 1);

    st[p] = min(st[2 * p], st[2 * p + 1]);

    return st[p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int> > > v;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (b < m - 1)
            b--;
        v.pb({c, {a, b}});
    }

    sort(v.begin(), v.end());

    int i = 0, j = 0;
    int mini = 1e9;
    
    while (i < n && j < n) {
        I = 0;
        J = m - 1;
        if (j < n && query(0, m - 1, 1) == 0) {
            I = v[j].s.f;
            J = v[j].s.s;
            value = 1;
            up(0, m - 1, 1);
            j++;
        }
        I = 0;
        J = m - 1;
        while (query(0, m - 1, 1) > 0) {
            mini = min(mini, v[j - 1].f - v[i].f);
            I = v[i].s.f;
            J = v[i].s.s;
            value = -1;
            up(0, m - 1, 1);
            I = 0;
            J = m - 1;
            i++;
        }
    }

    cout << mini << endl;
    return 0;
}