#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
 
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
 
    string s;
    cin >> s;
     
    int b1 = 0;
    int b2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            if (s[i] == '0')
            b1++;
            else
            {
                b2++;
            }
             
        } else  {
            if (s[i] == '1')
            b1++;
            else
            {
                b2++;
            }
        }
    }
    //int brojac = 0;
    cout<<min(b1,b2)<<endl;
    return 0;
}