#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const ll mod = 2147483647;
bool visi[1001][1001][2];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    static char mat[1001][1001];
    static ll dp[1001][1001];
    dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>mat[i][j];
	}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
			if(i!=0||j!=0)
            dp[i][j]=0;
            if(mat[i][j]=='#')
                continue;
            if(i-1>=0)
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j-1>=0)
                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    queue<int> qi,qj;
    visi[0][0][0]=visi[0][0][1]=true;
    qi.push(0);
    qj.push(0);
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        if(topi+1<n&&mat[topi+1][topj]!='#'&&visi[topi+1][topj][0]==false)
        {
            visi[topi+1][topj][0]=true;
            qi.push(topi+1);
            qj.push(topj);
        }
        if(topi-1>=0&&mat[topi-1][topj]!='#'&&visi[topi-1][topj][0]==false)
        {
            visi[topi-1][topj][0]=true;
            qi.push(topi-1);
            qj.push(topj);
        }
        if(topj+1<n&&mat[topi][topj+1]!='#'&&visi[topi][topj+1][0]==false)
        {
            visi[topi][topj+1][0]=true;
            qi.push(topi);
            qj.push(topj+1);
        }
        if(topj-1>=0&&mat[topi][topj-1]!='#'&&visi[topi][topj-1][0]==false)
        {
            visi[topi][topj-1][0]=true;
            qi.push(topi);
            qj.push(topj-1);
        }
    }
    qi.push(0);
    qj.push(0);
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topj=qj.front();
        qj.pop();
        if(topi+1<n&&mat[topi+1][topj]!='#'&&visi[topi+1][topj][1]==false)
        {
            visi[topi+1][topj][1]=true;
            qi.push(topi+1);
            qj.push(topj);
        }
        if(topj+1<n&&mat[topi][topj+1]!='#'&&visi[topi][topj+1][1]==false)
        {
            visi[topi][topj+1][1]=true;
            qi.push(topi);
            qj.push(topj+1);
        }
    }
    if(visi[n-1][n-1][1])
    {
        cout<<dp[n-1][n-1]<<endl;
    }
    else
    {
        if(visi[n-1][n-1][0])
            cout<<"THE GAME IS A LIE"<<endl;
        else
            cout<<"INCONCEIVABLE"<<endl;
    }
    return 0;
}