#include <iostream>
#include <string>
using namespace std;
string s;
bool g[7][7];
int rec(int x, int y, int i, char dir) {
 
    if (i == 48) {
        return 1;
    }
    if (g[6][0])
        return 0;
    if (dir != 'U' && (x == 6 || g[x+1][y]) && y - 1 >= 0 && y + 1 < 7 && !g[x][y - 1] && !g[x][y + 1])
        return 0;
    if (dir != 'D' && (x == 0 || g[x-1][y]) && y - 1 >= 0 && y + 1 < 7 && !g[x][y - 1] && !g[x][y + 1])
        return 0;
    if (dir != 'L' && (y == 6 || g[x][y+1]) && x - 1 >= 0 && x + 1 < 7 && !g[x - 1][y] && !g[x + 1][y])
        return 0;
    if (dir != 'R' && (y == 0 || g[x][y-1])&& x - 1 >= 0 && x + 1 < 7 && !g[x - 1][y] && !g[x + 1][y])
        return 0;
 
    int brojac = 0;
    if (s[i] == '?') {
        if (x - 1 >= 0 && !g[x - 1][y]) {
            g[x - 1][y] = true;
            brojac += rec(x - 1, y, i + 1, 'U');
            g[x - 1][y] = false;
        }
 
        if (y - 1 >= 0 && !g[x][y - 1]) {
            g[x][y - 1] = true;
            brojac += rec(x, y - 1, i + 1, 'L');
            g[x][y -1] = false;
        }
        if (y + 1 < 7 && !g[x][y + 1]) {
            g[x][y + 1] = true;
            brojac += rec(x, y + 1, i + 1, 'R');
            g[x][y + 1] = false;
        }
        if (x + 1 < 7 && !g[x + 1][y]) {
            g[x + 1][y] = true;
            brojac += rec(x + 1, y, i + 1, 'D');
            g[x + 1][y] = false;
        }
    }
    else if (s[i] == 'D') {
 
        if (x + 1 < 7 && !g[x + 1][y]) {
            g[x + 1][y] = true;
            brojac += rec(x + 1, y, i + 1, 'D');
            g[x + 1][y] = false;
        }
    }
    else if (s[i] == 'U') {
        if (x - 1 >= 0 && !g[x - 1][y]) {
            g[x - 1][y] = true;
            brojac += rec(x - 1, y, i + 1, 'U');
            g[x - 1][y] = false;
        }
    }
    else if (s[i] == 'R') {
        if (y + 1 < 7 && !g[x][y + 1]) {
            g[x][y + 1] = true;
            brojac += rec(x, y + 1, i + 1, 'R');
            g[x][y + 1] = false;
        }
    }
    else if (s[i] == 'L') {
        if (y - 1 >= 0 && !g[x][y - 1]) {
            g[x][y - 1] = true;
            brojac += rec(x, y - 1, i + 1, 'L');
            g[x][y -1] = false;
        }
    }
 
    return brojac;
}
int main() {
    cin >> s;
    g[0][0] = true;
    cout << rec(0, 0, 0, '-') << endl;
    return 0;
}