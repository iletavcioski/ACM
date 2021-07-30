#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

vector<bool> visi1(500000,false);
vector<bool> visi(500000,false);
vector<int> vis(500000, 0);
vector<int> fvis(500000, 0);
vector<bool> drugivis(500000, false);
vector<vector<int> > v,g;
vector<int> vec(500000,0);
stack<int> s;
map<int, bool> mm;
map<int, bool> mm1;
void dfs(int x)
{
    if(visi[x])
        return;
    visi[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
    }
    s.push(x);
}

void dfs2(int x,int broj)
{
    if(visi1[x])
        return;
    visi1[x]=true;
    vec[broj]++;
    vis[x] = broj;
    for(int i=0;i<g[x].size();i++)
    {
        dfs2(g[x][i],broj);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<int> ve;
        v.insert(v.begin(),n+1,ve);
        g.insert(g.begin(),n+1,ve);
        for (int i = 0 ; i < n; i++) {
            fvis[i] = 0;
            visi[i] = false;
            visi1[i] = false;
            vec[i] = 0;
            vis[i] = 0;
            drugivis[i] = false;
        }
        mm.clear();
        mm1.clear();
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (a == b) mm1[a] = true;
            v[a].pb(b);
            g[b].pb(a);
        }
        for(int i=0;i<n;i++)
        {
            if(!visi[i])
                dfs(i);
        }
        int brojac=1;

         while(!s.empty())
        {
            int topi=s.top();
            s.pop();
            if(!visi1[topi])
            {
                dfs2(topi,brojac);
                if (vec[brojac] > 1) mm[brojac] = true;
                brojac++;
            }
        }


        vector<int> res(n + 1, 0);
        queue<int> qi;
        queue<int> qs;
        qi.push(0);
        if (mm[vis[0]] || mm1[0])
            qs.push(-1), drugivis[0] = true;
        else
            qs.push(0);
        while (!qi.empty()) {

            int topi = qi.front();
            qi.pop();
            int tops = qs.front();
            qs.pop();
            //cout << topi << " " << tops << endl;
            if (tops == -1) {
                fvis[topi] = -1;
            }
            else
                fvis[topi]++;
            for (int i = 0; i < v[topi].size(); i++) {
                if (tops == 0) {
                    qi.push(v[topi][i]);
                    if (tops == 0 && (mm[vis[v[topi][i]]] || mm1[v[topi][i]]))
                        qs.push(-1);
                    else
                        qs.push(tops);
                } else if (tops == -1 && !drugivis[v[topi][i]]) {
                    qi.push(v[topi][i]);
                    qs.push(-1);
                    drugivis[v[topi][i]] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (fvis[i] == 1) res[i] = 1;
            else if (fvis[i] > 1) res[i] = 2;
            else if (fvis[i] == -1) res[i] = -1;
        }
        cout << "REZ" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << res[i] << " ";
        }
        cout << res[n - 1] << endl;

    }
    return 0;
}
/*
1

6 7
1 4
1 3
3 4
4 5
2 1
5 5
5 6
*/