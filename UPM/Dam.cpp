#include <bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
using namespace std;
typedef long long ll;
 
 
vector<ll> v;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n, k;
    ll m;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.pb(a);
    }
 
    ll l = 0, r = 1e18;
    ll maxi = 0;
    while (l <= r) {
        ll mid = (l+r)/2;
        ll br = 0;
 
        ll bro=0;
 
        vector<ll> vc(1000002,0);
       for (int i = 0; i < n; i++) {
            if (bro > m)
                break;
               br-=vc[i];
           if (v[i] + br >= mid)
               continue;
           else {
               ll bbr = mid - v[i] - br;
               br += bbr;
               bro += bbr;
               vc[min(n,i + k)] = bbr;
           }
 
       }
 
 
        if (bro > m) {
            r = mid-1;
        }
        else {
            maxi = max(maxi,mid);
            l = mid + 1;
        }
    }
 
    cout<<maxi<<endl;
    return 0;
}