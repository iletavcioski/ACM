#include <bits/stdc++.h>
using namespace std;
int N;
string s;
void solve(){
  int res = 0;
  for(int i=0;i<N-2;i++){
    if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0'){
      s[i+2] = '1';
      res = res + 1;
    }
  }
  cout << res << endl;
}
void read(){
  cin >> N;
  cin >> s;
}
int main () {
    read();
  solve();
  return 0;
}
