#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string a,b,s;
    s="";
    cin >> a >> b;
    int brojac = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (brojac % 2 == 0) s += a[i];
            else s += b[i];
            brojac++;
        } else {
            s += a[i];
        }
    }
    if (brojac % 2 == 1) {
        cout << "impossible" << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}