#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
//bool vis[10001][10001];
int vis1[10001];
int vis2[10001];
bool kraj[10001];
vector<int> vk;
vector<vector<int> > v;
stack<int> s;
vector<int> pot(10001, -1);
void bfs(int x, int b, int zaf) {
    queue<int> qi;
    qi.push(x);
    pot[x] = -1;
    vis2[x] = zaf;
    vector<int> pat;
    while (!qi.empty()) {
        int topi = qi.front();
        qi.pop();
        if (vis1[topi] == b && topi != x) {
            int y = topi;
            while (y != x) {
                pat.push_back(pot[y]);
               // vis[pot[y]][y] = true;
                //cout << pot[y] << " " << y << endl;
 
                vis1[pot[y]] = b;
                y = pot[y];
            }
            break;
        }
        for (int i = 0; i < v[topi].size(); i++) {
            if (vis2[v[topi][i]] != zaf && (vis1[v[topi][i]] != b || vis1[topi] != b)) {
                vis2[v[topi][i]] = zaf;
                qi.push(v[topi][i]);
                pot[v[topi][i]] = topi;
            }
        }
 
    }
    for (int i = 0; i < pat.size(); i++) {
        s.push(pat[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int V;
    cin >> V;
 
    vector<int> vec;
    v.insert(v.begin(), V+1, vec);
    int a, b;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        if (a == b)
            continue;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x, y;
    cin >> x >> y;
    vis1[y] = 1;
    s.push(x);
    int broj = 0;
    while (!s.empty()) {
        broj++;
        int g = s.top();
        s.pop();
        bfs(g, 1, broj);
    }
    for (int i = 0; i < V; i++) {
        if (vis1[i])
            vk.push_back(i);
    }
 
    sort(vk.begin(),vk.end());
    for (int i = 0 ; i < vk.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << vk[i];
    }
    cout << endl;
    return 0;
} 
