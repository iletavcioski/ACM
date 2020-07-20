#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int brojac = 0;
    int broj = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= broj) {
            broj += v[i];
            brojac++;
        }
    }
    cout << brojac << endl;
    return 0;
}