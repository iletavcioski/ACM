#include <bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
typedef long long ll;
 
vector<ll> seg(1000000,0);
vector<ll> v;
ll val;
int I,J;
void rek(int l, int r, int p) {
    if (l == r) {
        seg[p] = v[l];
        return;
    }
    rek(l,(l+r)/2,2*p);
    rek((l+r)/2+1,r,2*p+1);
    seg[p] = seg[2*p] + seg[2*p + 1];
 
    return;
}
 
ll query(int l, int r, int p) {
    //cout<<seg[p]<<" "<<l<<" "<<r<<endl;
    if (l >= I && r <= J)
        return seg[p];
    else if (I > r || J < l)
        return 0;
    else
        return query(l,(l+r)/2,2*p) + query((l+r)/2+1,r,2*p+1);
}
 
void update(int l, int r, int p) {
    if (I >= l && J <= r) {
        seg[p] = val;
        return;
    }
    else if (l > J || r < I)
        return;
    else {
        update(l,(l+r)/2,2*p);
        update((l+r)/2+1,r,2*p+1);
        seg[p] = seg[2*p] + seg[2*p + 1];
        return;
    }
}
 
int main()
{
   int n, q;
   cin >> n >> q;
   for (int i = 0; i < n; i++)
   {
       ll a;
       cin >> a;
       v.pb(a);
   }
   rek(0,n-1,1);
   for (int i = 0; i < q; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        I = a;
        J = b;
        cout<<query(0,n-1,1)<<endl;
   }
    return 0;
}