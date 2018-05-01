#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
static int dp[5001][5001];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string s1=s;
    reverse(s1.begin(),s1.end());
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int maxi=max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==s1[j-1])
                maxi=max(maxi,dp[i-1][j-1]+1);
            dp[i][j]=maxi;
        }
    }
    cout<<n-dp[n][n]<<endl;
    return 0;
} 