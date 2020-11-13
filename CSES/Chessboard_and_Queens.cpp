#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
vector<string> v;
vector<int> v1;
int maxi=0;
int br = 0;
void rek(int i) {
    if (i == 8) {
        br++;
        return;
    }
 
    for (int j = 0; j < 8; j++) {
        if (v[i][j] == '*')
            continue;
        bool cc = true;
        for (int k = 0; k < i; k++) {
            if (v1[k] == j || v1[k] == j + (i - k) || v1[k] == j - (i - k)) {
                cc = false;
                break;
            }
        }
        if (!cc)
            continue;
        v1.push_back(j);
        rek(i + 1);
        v1.pop_back();
    }
}
int main() {
   for (int i = 0; i < 8; i++) {
      string s;
      cin >> s;
      v.push_back(s);
   }
   rek(0);
   cout<<br<<endl;
   return 0;
}