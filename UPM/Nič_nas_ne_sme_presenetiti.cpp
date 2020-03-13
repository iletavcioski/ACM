#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> > v;
vector<int> vis(1000001, 0);
int ostanati;
int br = 1;
void solve(int mom){
  ostanati--;
  if (!ostanati)
  return;
  vis[mom]= 0;
  for (int i = 0; i < v[mom].size(); i++) {
    if (vis[v[mom][i]] == br) {
      solve(v[mom][i]);
    }
  }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n, q;
  cin >> n >> q;
  vector<int> vec;
  v.insert(v.begin(), n + 1, vec);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  //cout<<"d"<<endl;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    ostanati = m;
    int a;
    int prv = -1;
    for (int j = 0; j < m; j++) {
      cin >> a;
      if (prv == -1)
        prv = a - 1;
      a--;
      vis[a] = br;
    }
    solve(a);
    br++;
    if (ostanati == 0) {
      cout<<"ALAAAARHM"<<endl;
    }
     else {
       cout <<"NASLEDNJI"<<endl;
     }
  }
}