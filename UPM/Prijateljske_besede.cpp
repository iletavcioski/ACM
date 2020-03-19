#include <bits/stdc++.h>
 
#define f first
// #define s second
#define pb push_back
#define mp make_pair
using namespace std;
 
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    vector<string> s;
    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(), n+1,vec);
     
    for (int i = 0; i<n; i++) {
        string a;
        cin >> a;
        s.pb(a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
             
            string s1 = s[i].substr(0,3);
            string s2 = s[j].substr(0,3);
            string s3 = s[i].substr(s[i].size()-3,3);
            string s4 = s[j].substr(s[j].size()-3,3);
            if (s1 == s2 || s3 == s4)
                v[i].pb(j),v[j].pb(i);
        }
    }
    vector<int> vis(n+1,0);
    queue<int> qi;
    qi.push(0);
 
    while (!qi.empty()) {
        int x = qi.front();
        qi.pop();
        if (vis[x] == 1)
        continue;
        vis[x] = 1;
        for (int i = 0; i < v[x].size(); i++) {
            qi.push(v[x][i]);
        }
    }
    int brojac = 0;
    string s1 = s[0].substr(0,3);
    string s3 = s[0].substr(s[0].size()-3,3);
    for (int i = 1; i < n; i++) {
        if (vis[i]){
            string s2 = s[i].substr(0,3);
            string s4 = s[i].substr(s[i].size()-3,3);
            if (s1 != s2 || s3 != s4)
            brojac++;
        }
    }
    cout<<brojac+1<<endl;
    return 0;
}