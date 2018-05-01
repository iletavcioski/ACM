#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--)
    {
        static char mat[110][101][101];
        int x;
        cin>>x;
        int n,m;
        cin>>n>>m;
        n+=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j][0];
            }
        }
        for(int k=1;k<m;k++)
        {
            for(int i=0;i<n;i++)
            {
                if(i!=0&&i!=n-1)
                {
                    for(int j=0;j<m;j++)
                    {
						int jj;
						if(i%2==(n-2)%2)
						{
							jj=j-1;
                        if(jj==-1)
                            jj=m-1;
						}
						else
						{
							jj=j+1;
							if(jj==m)
								jj=0;
						}
                        mat[i][j][k]=mat[i][jj][k-1];
                    }
                }
				else
				{
					for(int j=0;j<m;j++)
                    {
                        int jj=j;
                        mat[i][j][k]=mat[i][jj][k-1];
                    }
				}
            }
        }
        queue<int> qi;
        queue<int> qj;
        queue<int> qs;
        queue<int> qn;
        int maxi=1e9;
        static int visi[110][101][101];
        for(int k=0;k<m;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j][k]=='F'&&k==0)
                    {
                        visi[i][j][k]=0;
                        qi.push(i);
                        qj.push(j);
                        qs.push(0);
                        qn.push(0);
                    }
                    else
                    {
                        visi[i][j][k]=1e9;
                    }
                }
            }
        }
		

        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topj=qj.front();
            qj.pop();
            int tops=qs.front();
            qs.pop();
            int topn=qn.front();
            qn.pop();
            int nov=(topn+1)%m;
            if(mat[topi][topj][0]=='G')
            {
                maxi=min(maxi,tops);
                continue;

            }
            if(topi+1<n&&tops+1<visi[topi+1][topj][nov]&&mat[topi+1][topj][nov]!='X')
            {
                visi[topi+1][topj][nov]=tops+1;
                qi.push(topi+1);
                qj.push(topj);
                qs.push(tops+1);
                qn.push(nov);
            }
            if(topi-1>=0&&tops+1<visi[topi-1][topj][nov]&&mat[topi-1][topj][nov]!='X')
            {
                visi[topi-1][topj][nov]=tops+1;
                qi.push(topi-1);
                qj.push(topj);
                qs.push(tops+1);
                qn.push(nov);
            }
            if(topj+1<m&&tops+1<visi[topi][topj+1][nov]&&mat[topi][topj+1][nov]!='X')
            {
                visi[topi][topj+1][nov]=tops+1;
                qi.push(topi);
                qj.push(topj+1);
                qs.push(tops+1);
                qn.push(nov);
            }
            if(topj-1>=0&&tops+1<visi[topi][topj-1][nov]&&mat[topi][topj-1][nov]!='X')
            {
                visi[topi][topj-1][nov]=tops+1;
                qi.push(topi);
                qj.push(topj-1);
                qs.push(tops+1);
                qn.push(nov);
            }
            if(tops+1<visi[topi][topj][nov]&&mat[topi][topj][nov]!='X')
            {
                visi[topi][topj][nov]=tops+1;
                qi.push(topi);
                qj.push(topj);
                qs.push(tops+1);
                qn.push(nov);
            }
        }
        if(maxi>x)
        {
            cout<<"The problem has no solution."<<endl;
        }
        else
        {
            cout<<"The minimum number of turns is "<<maxi<<"."<<endl;
        }
    }
    return 0;
}