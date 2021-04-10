#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        map<int,int> m;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
            m[a]++;
        }
        for (int i = 0; i < n; i++) {
            if (m[v[i]] == 1) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}