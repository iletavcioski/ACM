#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[81][(1<<20)];
int mat[81][20][20];
bool v[81][(1<<20)];
ll rek(int a,int bitmask,int broj)
{
    if(v[a][bitmask]!=0)
        return dp[a][bitmask];
	v[a][bitmask]=true;
    ll brojac=0;
    if(broj==0)
    {
        int ind=-1;
        for(int i=0;i<20;i++)
        {
            if(bitmask&(1<<i))
                ind=i;
        }
        return dp[a][bitmask]=mat[a][broj][ind];
    }
    for(int i=0;i<20;i++)
    {
        if((bitmask&(1<<i))&&mat[a][broj][i])
            brojac+=rek(a,bitmask^(1<<i),broj-1);
    }
    return dp[a][bitmask]=brojac;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++)    
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>mat[tt][i][j];
        }
        cout<<rek(tt,(1<<n)-1,n-1)<<endl;
    }
    return 0;
} 