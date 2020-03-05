#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
int main() {
    int n;
    cin >> n;
    vector<ll> v;
    ll zbir = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        zbir += a;
    }
    sum = zbir;
    vector<ll> v1,v2;
    zbir /= 2;
    int b = n/2;
    if (n%2)
    b++;
    for (int i = 0; i < (1<<b); i++) {
        ll bro = 0;
        for (int j = 0; j < b; j++) {
            if ((1<<j)&i)
            bro += v[j];
        }
        v1.push_back(bro);
    }
    int b1 = n/2;
    for (int i = 0; i < (1<<b1); i++) {
        ll bro = 0;
        for (int j = 0;j<b1;j++) {
            if ((i&(1<<j))&&b+j < n) {
                bro+=v[b+j];
            }
        }
        v2.push_back(bro);
    }
    sort(v2.begin(),v2.end());
    ll maxi = 1e18;
    /*
    for (int i = 0; i < v1.size(); i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0 ;i  < v2.size(); i++)
        cout<<v2[i]<<" ";
    cout<<endl;
 
    */
 
 
    for (int i = 0; i < v1.size(); i++) {
        int l = 0,r = v2.size()-1;
        int aa = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (v2[mid]<=(zbir-v1[i])) {
                aa = max(aa,mid);
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        if (aa == -1)
        continue;
      //  cout<<aa<<endl;
        maxi = min(maxi,abs((sum-(v1[i]+v2[aa]))-(v1[i]+v2[aa])));
    }
    cout<<maxi<<endl;
    return 0;
}