#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    int brojac = 1;
    int poc = v[0].first;
    for (int i = 1; i < n - 1; i++) {
        
        if ((v[i].first - v[i].second) > poc) {
            brojac++;
            poc = v[i].first;
        } else if ((v[i].first + v[i].second) < v[i + 1].first) {
            poc = v[i].first + v[i].second;
            brojac++;
        } else {
        poc = v[i].first;
        }
    }
    if (n > 1) brojac++;
    cout << brojac << endl;
    return 0;
}