#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;

    vector<pair<ll,ll> > v;
    v.push_back(make_pair(0,0));
    v.push_back(make_pair(0,0));
    for (ll i = 0; i < 2*n; i++) {
        ll a;
        cin>>a;
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    ll dp[n+1][2];
    dp[0][0]=0;
    dp[0][1]=0;
    int br = 1;
    for (int i = 2; i < 2*n + 2; i+=2) {
        dp[br][0] = min(dp[br - 1][0] + abs(v[i - 2].second-v[i].second) + abs(v[i - 1].second-v[i+1].second),dp[br - 1][1] + abs(v[i - 1].second - v[i].second) + abs(v[i-2].second-v[i+1].second));
        dp[br][1] = min(dp[br-1][0] + abs(v[i-2].second - v[i+1].second)+abs(v[i-1].second-v[i].second),dp[br-1][1] + abs(v[i-1].second - v[i+1].second) + abs(v[i-2].second - v[i].second));
        br++;
        //cout<<dp[br-1][0]<<" "<<dp[br-1][1]<<endl;
    }
    cout<<min(dp[n][0],dp[n][1])<<endl;
    return 0;
}