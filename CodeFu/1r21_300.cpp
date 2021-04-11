#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class IntergalacticCake
{
public:
    bool vis[200][200];
    int mat[200 + 1][200 + 1][4];
    void dfs(int n, int i, int j) {
        //cout << i << " " << j << endl;
        vis[i][j] = true;
        if (i + 1 < n && mat[i][j][3] == 0 && !vis[i + 1][j]) {
            dfs(n, i + 1, j);
        }

        if (i - 1 >= 0 && mat[i][j][1] == 0 && !vis[i - 1][j]) {
            dfs(n, i - 1, j);
        }

        if (j + 1 < n && mat[i][j][2] == 0 && !vis[i][j + 1]) {
            dfs(n, i, j + 1);
        }

        if (j - 1 >= 0 && mat[i][j][0] == 0 && !vis[i][j - 1]) {
            dfs(n, i, j - 1);
        }
    }
    int getSlices(int N, int M, vector<int> hCuts, vector<int> vCuts)
    {
        if (N == M) return 0;
        int n = 2 * N;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++)
                    mat[i][j][k] = 0;
            }
        }
        int cx = N;
        int cy = N;
        int x = N - M - 1;
        int y = N - M - 1;
        int m = 2 * M;
        for (int i = 0; i < 200; i++)
            for (int j = 0; j < 200; j++)
                vis[i][j] = 0;
        for (int i = 1; i <= m; i++) {
            mat[x][y + i][3] = 1;
            mat[x + 1][y + i][1] = 1;
        }
        y += m;
        y++;
        for (int i = 1; i <= m; i++) {
            mat[x + i][y][0] = 1;
            mat[x + i][y - 1][2] = 1;
        }
        x += m;
        x++;
        for (int i = 1; i <= m; i++) {
            mat[x][y - i][1] = 1;
            mat[x - 1][y - i][3] = 1;
        }
        y -= m;
        y--;
        for (int i = 1; i <= m; i++) {
            mat[x - i][y][2] = 1;
            mat[x - i][y + 1][0] = 1;
        }
        x -= m;
        x--;
        queue<int> qi;
        queue<int> qj;
        qi.push(N - M);
        qj.push(N - M);
        while (!qi.empty()) {
            int ti = qi.front();
            qi.pop();
            int tj = qj.front();
            qj.pop();
            vis[ti][tj] = 1;
            if (mat[ti][tj][1] == 0 && ti - 1 >= 0 && vis[ti - 1][tj] == 0) {
                vis[ti - 1][tj] = 1;
                qi.push(ti - 1);
                qj.push(tj);
            }

            if (mat[ti][tj][0] == 0 && tj - 1 >= 0 && vis[ti][tj - 1] == 0) {
                vis[ti][tj  - 1] = 1;
                qi.push(ti);
                qj.push(tj - 1);
            }

            if (mat[ti][tj][3] == 0 && ti + 1 < n && vis[ti + 1][tj] == 0) {
                qi.push(ti + 1);
                qj.push(tj);
                vis[ti  +1][tj] = 1;
            }

            if (mat[ti][tj][2] == 0 && tj + 1 < n && vis[ti][tj + 1] == 0) {
                qi.push(ti);
                qj.push(tj + 1);
                vis[ti][tj  + 1] = 1;
            }
        }
       /* for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
*/
        for (int i = 0; i < hCuts.size(); i++) {
            if (hCuts[i] <= 0) {
                hCuts[i] *= -1;
                for (int j = 0; j < n; j++) {
                    mat[N - 1 + hCuts[i]][j][3] = 1;
                    mat[N + hCuts[i]][j][1] = 1;
                }
            } else {
                hCuts[i] *= -1;
                for (int j = 0; j < n; j++) {
                    mat[N + hCuts[i]][j][1] = 1;
                    mat[N - 1 + hCuts[i]][j][3] = 1;
                }
            }
        }
        /*cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j][1] << " ";
            }
            cout << endl;
            for (int j = 0; j < n; j++) {
                cout << vis[i][j] << " ";
            }
            cout << endl;


        }
         */
        for (int i = 0; i < vCuts.size(); i++) {
            if (vCuts[i] >= 0) {
                for (int j = 0; j < n; j++) {
                    mat[j][N - 1 + vCuts[i]][2] = 1;
                    mat[j][N + vCuts[i]][0] = 1;
                }
            } else {
                for (int j = 0; j < n; j++) {
                    mat[j][N + vCuts[i]][0] = 1;
                    mat[j][N - 1 + vCuts[i]][2] = 1;
                }
            }
        }
        int brojac = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    brojac++;
                    dfs(n, i, j);
                }
            }
        }
        return brojac;
    }
};
int main() {
    IntergalacticCake x;
    cout << x.getSlices(38, 15, {-12,-30,27,37,-26,-16,2,-31,29,32,14,9,-28,28,4,-18,-27,-34}, {18,0,26,-9,36,-4,-37,15,-8,7,-20,29,35,16})  << endl;
}
