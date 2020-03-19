#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
 
typedef long long ll;
 
int to_day(string in) {
    if (in == "januar") return 0;
    if (in == "februar") return 31;
    if (in == "marec") return 59;
    if (in == "april") return 90;
    if (in == "maj") return 120;
    if (in == "junij") return 151;
    if (in == "julij") return 181;
    if (in == "avgust") return 212;
    if (in == "september") return 243;
    if (in == "oktober") return 273;
    if (in == "november") return 304;
    if (in == "december") return 334;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll z;
        double f;
        string dan, mesec, leto;
        cin >> z >> f >> dan >> mesec >> leto;
        ll F = (ll)(round(f * 100 + 0.1) + 0.1);
        ll Z = z * 100;
        dan.pop_back();
        ll day;
        sscanf(dan.c_str(), "%lld", &day);
        day += to_day(mesec);
        if (day < 110) {
            cout << "V SMETI" << endl;
            continue;
        }
        day -= 109;
        if (day * F >= Z)
         cout << "OK" << endl;
        else
        cout << "AKCIJA" << endl;;
    }
    return 0;
}
