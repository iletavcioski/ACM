#include <vector>
#include <queue>
#include <string>
using namespace std;

class Minescape
{
  public:
    int escape(vector<string> maze)
    {
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
    static bool dp[25][25][16][(1<<15)];
        int maz[25][25];
        char mat[25][25];
        int n=maze.size();
        int m=maze[0].size();
        int br=0;
        int pi,pj,ei,ej;
        for(int i=0;i<maze.size();i++)
        {
            for(int j=0;j<maze[i].size();j++)
            {
                mat[i][j]=maze[i][j];
                if(maze[i][j]==' ')
                    mat[i][j]='.';
                if(mat[i][j]=='@')
                {
                    maz[i][j]=br;
                    br++;
                }
                else
                {
                    maz[i][j]=-1;
                }
                if(mat[i][j]=='S')
                    pi=i,pj=j;
                if(mat[i][j]=='E')
                    ei=i,ej=j;
            }
        }
        int maxi=1000000001;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<=br;k++)
                {
                    for(int l=0;l<(1<<br);l++)
                        dp[i][j][k][l]=0;
                }
            }
        }
        dp[pi][pj][0][0]=1;
        queue<int> qi;
        queue<int> qj;
        queue<int> qt;
        queue<int> qb;
        queue<int> qs;
        qi.push(pi);
        qj.push(pj);
        qs.push(0);
        qt.push(0);
        qb.push(0);
        while(!qi.empty())
        {
            int ti=qi.front();
            qi.pop();
            int tj=qj.front();
            qj.pop();
            int tb=qb.front();
            qb.pop();
            int tops=qs.front();
            qs.pop();
            int tt=qt.front();
            qt.pop();
            if(ti==ei&&tj==ej)
            {
                maxi=min(maxi,tops);
            }
            else {
            for(int i=0;i<4;i++)
            {
                if(ti+x[i]<n&&ti+x[i]>=0&&tj+y[i]<m&&tj+y[i]>=0)
                {
                    int a=ti+x[i];
                    int b=tj+y[i];
                    if((mat[a][b]=='.'||mat[a][b]=='E'||mat[a][b]=='S')&&!dp[a][b][tt][tb])
                    {
                        qi.push(a);
                        qj.push(b);
                        qt.push(tt);
                        qb.push(tb);
                        qs.push(tops+1);
                        dp[a][b][tt][tb]=1;
                    }
                    if(mat[a][b]=='#'&&tt>0)
                    {
                        if(!dp[a][b][tt-1][tb])
                        {
                            qi.push(a);
                            qj.push(b);
                            qt.push(tt-1);
                            qb.push(tb);
                            qs.push(tops+1);
                            dp[a][b][tt-1][tb]=1;
                        }
                    }
                    if(mat[a][b]=='@'&&!(tb&(1<<maz[a][b])))
                    {
                        if(!dp[a][b][tt+1][tb|(1<<maz[a][b])])
                        {
                            qi.push(a);
                            qj.push(b);
                            qt.push(tt+1);
                            qb.push(tb|(1<<maz[a][b]));
                            qs.push(tops+1);
                            dp[a][b][tt+1][tb|(a<<maz[a][b])]=1;
                        }
                    }
                    if(mat[a][b]=='@'&&(tb&(1<<maz[a][b])))
                    {
                        if(!dp[a][b][tt][tb])
                        {
                            qi.push(a);
                            qj.push(b);
                            qs.push(tops+1);
                            qt.push(tt);
                            qb.push(tb);
                            dp[a][b][tt][tb]=1;
                        }
                    }
                }
            }
        }
        }

        if(maxi==1000000001)
            return -1;
        else
            return maxi;
  }
};