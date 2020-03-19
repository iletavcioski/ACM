#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
struct ed {
    int a,b;
};
vector<int> p(1000001,-1);
vector<int> d(1000001,0);
int dsu(int a) {
    if (p[a] == -1)
        return a;
    else
        return dsu(p[a]);
}
void dsu1(int a, int b) {
    if (p[a] != b) {
        int c = p[a];
        p[a]=b;
        dsu1(c,b);
    }
    else
        return;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<ed> v;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    int q;
    cin >> q;
    vector<int> inn;
    vector<int> vis(m+10,0);
    for (int i =0; i < q; i++) {
        int a;
        cin >> a;
        a--;
        vis[a] = true;
        inn.push_back(a);
    }
    int br = n;
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            int a = v[i].a;
            int b = v[i].b;
 
 
            a = dsu(a);
            b = dsu(b);
            if (a == b&&a!=-1)
                continue;
            else {
                if (d[a] > d[b]) {
                    p[a] = b;
                    int aa = v[i].a;
                    dsu1(aa,b);
                }
                else if(d[a]<d[b]) {
                    p[b] = a;
                    int aa=v[i].b;
                    dsu1(aa,a);
                }
                else {
                    p[b] = a;
                    d[a]++;
                }
                br--;
            }
        }
    }
    vector<int> vc;
 
    for (int i = q-1; i >= 0; i--) {
        int in = inn[i];
        int a = v[in].a;
        int b = v[in].b;
 
        vc.push_back(br);
        a = dsu(a);
        b = dsu(b);
        if (a == b&&a!=-1)
            continue;
        else {
            if (d[a] > d[b]) {
                p[a] = b;
                int aa = v[in].a;
                dsu1(aa,b);
            }
            else if(d[a]<d[b]) {
                p[b] = a;
                int aa=v[in].b;
                dsu1(aa,a);
            }
            else {
                p[b] = a;
                d[a]++;
            }
            br--;
        }
    }
    reverse(vc.begin(),vc.end());
    for (int i = 0; i < q; i++) {
            if (i)
            cout<<" ";
        cout<<vc[i];
    }
    cout<<endl;
    return 0;
}