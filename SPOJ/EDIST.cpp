#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    static int dp[5001][5001];
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    int n=s.size();
    int m=s1.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			dp[i][j]=0;
	}
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(s[i-1]==s1[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
			{
            int maxi=min(dp[i-1][j],dp[i][j-1]);
                maxi=min(maxi,dp[i-1][j-1]);
            dp[i][j]+=maxi+1;
			}
        }
    }
    cout<<dp[n][m]<<endl;
    }
    return 0;
} 