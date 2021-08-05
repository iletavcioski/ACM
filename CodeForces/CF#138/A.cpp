#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string ss;
    cin >> ss;


    int maxi = 0;
    stack<int> st;
    vector<int> vis(ss.size() + 1, 0);
    int n = ss.size();
    vector<pair<int,int> > rez;
    rez.clear();
    for (int j = 0; j <= n; j++) {
        rez.push_back(make_pair(-1, -1));
    }
    vis[0] = 0;
    for (int i = 0; i < ss.size(); i++) {
        if (st.size() == 0) {
            vis[i + 1] = i + 1;
            st.push(i);
        } else {
            int idx = st.top();

            if (ss[idx] == '(' && ss[i] == ')') {
                st.pop();
            } else if (ss[idx] == '[' && ss[i] == ']') {
                st.pop();
            } else {
                st.push(i);
            }
            if (st.size() == 0) {
                vis[i + 1] = 0;
            } else {
                vis[i + 1] = st.top() + 1;
            }
        }
    }
    vector<int> dp(ss.size() + 2, 0);

    for (int i = 0; i < ss.size(); i++) {
        if (ss[i] == '[') dp[i + 1] = dp[i] + 1;
        else dp[i + 1] = dp[i];
    }




    for (int i = 0; i <= ss.size(); i++) {
        //cout << vis[i] << " ";
        if (rez[vis[i]].f == -1) rez[vis[i]].f = i;
        else rez[vis[i]].s = i;
    }
    //cout << endl;
    int fst, last;
    for (int i = 0; i <= ss.size(); i++) {
        //cout << rez[i].f << " " << rez[i].s << endl;
        if (rez[i].f == -1 || rez[i].s == -1)
            continue;
        int  res = dp[rez[i].s] - dp[rez[i].f];
        if (res > maxi) {
            fst = rez[i].f;
            last = rez[i].s - 1;
            maxi = res;
        }
    }
    cout << maxi << endl;
    if (maxi > 0) {
        //cout << fst << " " << last << endl;
        for (int i = fst; i <= last; i++) {
            cout << ss[i];
        }
        cout << endl;
    }
    return 0;
}