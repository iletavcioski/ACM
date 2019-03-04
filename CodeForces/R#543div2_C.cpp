#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

int main() {
   int n, m;
   cin>>n>>m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int I = 0;
    vector<int> t;
    vector<int> ti;
    vector<int> kt;
    for (int i = 0; i < m; i++) {
        t.push_back(-1);
        ti.push_back(-1);
        kt.push_back(-1);
    }
    set<int> ss;
    int brojac = 0;
    int mm = 0;
    bool cc=1;
    while (cc) {
        int br = 0;

        for (int i = 0; i < m; i++)
        {
            if (ti[i] != -1 && t[i] >= 1) {
            if (t[i] <= ti[i]) {
                t[i]++;
                if (t[i] > ti[i]) {
                    mm++;
                    t[i] = -1;
                    ti[i] = -1;
                    kt[i] = -1;
                }
            }
            }
        }
        for (int j = 0; j < m; j++) {
            if (t[j] == -1 && I < n) {
                ti[j] = v[I];
                t[j] = 1;
                kt[j] = I;
                I++;
            }

        }
        if (mm == n)
            break;
        for (int i = 0; i < m; i++) {
            double bbb = (double)mm/(double)n;
            double a = ((double)100*bbb) + 0.5;
            int bb = a;
           // cout<<bb<<"l";
            if (bb == t[i] && ti[i] != -1) {
                brojac++;
                ss.insert(kt[i]);
               // cout<<"------------------------------------------"<<endl;

            }

        }


    }
    cout<<ss.size()<<endl;
    return 0;
}