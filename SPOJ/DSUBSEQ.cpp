#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string ss;
        cin>>ss;
        int n=ss.size();
        vector<ll> dp(n+1,0);
        dp[0]=1;
        vector<int> v(26,-1);
		vector<int> dp1(n+1,0);
		dp1[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(dp1[i-1])%mod;
            if(v[ss[i-1]-'A']!=-1)
            {
                dp[i]-=dp1[v[ss[i-1]-'A']-1];
                while(dp[i]<0)
                    dp[i]+=mod;
                dp[i]%=mod;
            }
			dp1[i]=dp1[i-1];
			dp1[i]+=dp[i];
			dp1[i]%=mod;
            v[ss[i-1]-'A']=i;
        }
		ll brojac=0;
		cout<<dp1[n]<<endl;
    }
    return 0;
} 