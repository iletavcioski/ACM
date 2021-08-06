#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

int st1[400000];
ll st2[400000];
int laz1[400000];
ll laz2[400000];
int I, J;
ll value;
ll v[100001];

void build(int l, int r, int p) {
    if (l == r) {
        st2[p] = v[l];
        return;
    }

    build(l, (l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);
    st2[p] = st2[2 * p] + st2[2 * p + 1];
    return;
}
void up(int l, int r, int p) {

    if (laz1[p] != 0) {
        st1[p] += laz1[p] * (r - l + 1);
        if (l != r) {
            laz1[2 * p] += laz1[p];
            laz1[2 * p + 1] += laz1[p];
        }
        laz1[p] = 0;
    }

    if (l >= I && r <= J) {
        st1[p] +=  (int)value * (r - l + 1);
        if (l != r) {
            laz1[2 * p] += (int)value;
            laz1[2 * p + 1] += (int)value;
        }
        return;
    }



    if (l > J || r < I) {
        return;
    }


    up(l, (l + r) / 2, 2 * p);
    up((l + r) / 2 + 1, r, 2 * p + 1);

    st1[p] = st1[2 * p] + st1[2 * p + 1];
    return;
}

int qu1(int l, int r, int p) {
    if (laz1[p] != 0) {
        st1[p] += laz1[p] * (r - l + 1);
        if (l != r) {
            laz1[2 * p] += laz1[p];
            laz1[2 * p + 1] += laz1[p];
        }
        laz1[p] = 0;
    }

    if (l >= I && r <= J) {
        return st1[p];
    }

    if (l > J || r < I) {
        return 0;
    }
    return (qu1(l, (l + r) / 2, 2 * p) + qu1((l + r) / 2 + 1, r, 2 * p + 1));
}

ll qu2(int l, int r, int p) {
    if (laz2[p] != 0) {
        st2[p] += laz2[p] * (ll)(r - l + 1);
        if (l != r) {
            laz2[2 * p] += laz2[p];
            laz2[2 * p + 1] += laz2[p];
        }
        laz2[p] = 0;
    }

    if (l >= I && r <= J) {
        return st2[p];
    }

    if (l > J || r < I) {
        return 0;
    }

    return (qu2(l, (l + r) / 2, 2 * p) + qu2((l + r) / 2 + 1, r, 2 * p + 1));
}

void up2(int l, int r, int p) {

    if (laz2[p] != 0) {
        st2[p] += laz2[p] * (ll)(r - l + 1);
        if (l != r) {
            laz2[2 * p] += laz2[p];
            laz2[2 * p + 1] += laz2[p];
        }
        laz2[p] = 0;
    }

    if (l >= I && r <= J) {
        st2[p] +=  value * (ll)(r - l + 1);
        if (l != r) {
            laz2[2 * p] += value;
            laz2[2 * p + 1] += value;
        }
        return;
    }



    if (l > J || r < I) {
        return;
    }


    up2(l, (l + r) / 2, 2 * p);
    up2((l + r) / 2 + 1, r, 2 * p + 1);

    st2[p] = st2[2 * p] + st2[2 * p + 1];
    return;
}

struct que
{
    int a, b;
    ll c;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v[i] = a;
    }
    build(0, n - 1, 1);
    vector<que> queries;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ll c;
        cin >> c;
        a--;
        b--;
        queries.pb({a, b, c});
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        I = a;
        J = b;
        value = 1;
        up(0, m - 1, 1);
    }

    vector<ll> vis(m, 0);
    for (int i = 0; i < m; i++) {
        I = i, J = i;
        vis[i] = qu1(0, m - 1, 1);
        //cout << vis[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < m; i++) {
        I = queries[i].a;
        J = queries[i].b;
        value = queries[i].c * vis[i];
        up2(0, n - 1, 1);
    }
    for (int i = 0; i < n; i++) {
        I = i, J = i;
        v[i] = qu2(0, n - 1, 1);
    }
    for (int i = 0; i < n - 1; i++) cout << v[i] << " ";
    cout << v[n - 1] << endl;
    return 0;
}