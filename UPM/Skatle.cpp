#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
 
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<vector<int> > v;
    
     
    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        v.push_back(vec);
 
 
    }
    sort(v.begin(),v.end());
    //cout<<"d"<<endl;
   int maxi = 1;
    vector<int> dp(n + 1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool cc = true;
            for (int k = 0; k < d; k++) {
                if (v[i][k] >= v[j][k])
                cc=false;
            }
            if (cc) {
            dp[j] = max(dp[j],dp[i]+1);
            maxi = max(maxi,dp[j]);
            }
        }
    }
 
    cout<<maxi<<endl;
    return 0;
}