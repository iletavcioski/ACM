#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        bool cc = false;
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1 || a == 3) cc = true;
        }
        if (!cc) v.push_back(i);
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
    return 0;
}