#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k, n;
vector<int> vreme;
vector<int> cena;
ll zbir_cena;
ll zbir_time;
void solve(){
  ll maxi = -1;
  int i = 0, j = 0;
    int slobodnovreme = 0;
    while (i < n && j < n) {
         
        while (slobodnovreme < k && j < n) {
            slobodnovreme += vreme[j];
            zbir_time -= vreme[j];
            zbir_cena -= cena[j];
            j++;
        }
        while (slobodnovreme >= k && i < n) {
          maxi = max(maxi, zbir_cena);
          zbir_time += vreme[i];
          zbir_cena += cena[i];
          slobodnovreme -= vreme[i];
          i++;
        }
    }
  if (maxi == -1) {
    cout << "Tekma bo polom" << endl;
  } else {
    cout << maxi << endl;
  }
}
void read(){
    cin >> k;
  cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        zbir_cena += b;
        zbir_time += a;
        vreme.push_back(a);
        cena.push_back(b);
    }
}
int main () {
    read();
  solve();
  return 0;
}
