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
 
    double l, r;
    int n;
    cin >> l >> r;
    cin >> n;
    vector<double> v;
    double mn = 10;
    for (int i = 0; i <= n; i++) {
        double a;
        cin >> a;
 
        v.pb(a);
    }
    vector<int> vc;
    reverse(v.begin(),v.end());
 
    double i = l;
    while(i < r+0.1) {
 
        double br = 0.0;
        for (double j = n; j >= 0; j--) {
            double brr = pow(i,j) + 0.000001;
            brr *= v[j];
 
            br += brr;
        }
 
        br *= mn;
 
        int bc;
         
        if (br >= 0.0001)
            br+=0.05,bc = floor(br + 0.000000000011);
        else
            bc = br;
        int bk = br;
        if (br < -0.000000001 && abs((double)bc - br) > 0.0001)
            bc -=1;
        // if (bc >= 0 && (double)bc < br )
        //   bc++;
        //cout<<br<<endl;
        //cout<<(int)(bc)<<endl;
 
        vc.pb(bc);
        double cc = -0.1;
        if (i >= -0.1 && i < -0.00000000001)
            i=0;
        else
            i+=0.1000001;
        //cout<<i<<endl;
    }
    int maxi = 1e9;
    int mini = -1e9;
 
    for (int i = 0; i < vc.size(); i++) {
        maxi = min(maxi,vc[i]);
        mini = max(mini,vc[i]);
    }
    maxi -= 2;
    mini += 3;
    vector<string> vk;
    for (int i = maxi; i <= mini; i++) {
        string s1 = "";
        for (int j = 0; j < vc.size(); j++) {
            if (vc[j] >= i)
                s1+='#';
            else
                s1+='.';
        }
        vk.pb(s1);
    }
    for (int i = vk.size()-1; i >=0; i--)
        cout<<vk[i]<<endl;
    return 0;
}