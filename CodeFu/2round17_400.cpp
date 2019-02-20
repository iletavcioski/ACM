#include <string>
#include <vector>
#include<queue>
using namespace std;

class LazyGuards
{
  public:
    int numberOfSteps(vector<string> maze)
    {
  char mat[55][55][4];
  int n,m;
  n=maze.size();
  m=maze[0].size();
  int ei,ej,pi,pj;
  for(int i=0;i<maze.size();i++)
  {
    for(int j=0;j<maze[i].size();j++)
    {
      mat[i][j][0]=maze[i][j];
      if(mat[i][j][0]=='S')
        ei=i,ej=j;
      if(mat[i][j][0]=='E')
        pi=i,pj=j;
    }
  }
  for(int k=1;k<4;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(mat[i][j][k-1]=='1')
          mat[i][j][k]='2';
        else if(mat[i][j][k-1]=='2')
          mat[i][j][k]='3';
        else if(mat[i][j][k-1]=='3')
          mat[i][j][k]='4';
        else if(mat[i][j][k-1]=='4')
          mat[i][j][k]='1';
        else mat[i][j][k]=mat[i][j][k-1];
      }
    }
  }
  int dist[55][55][4];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<4;k++)
        dist[i][j][k]=1e9;
    }
  }
  for(int k=0;k<4;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(mat[i][j][k]=='1')
        {
          for(int jj=j+1;jj<m;jj++)
          {
            if(mat[i][jj][k]=='.'||mat[i][jj][k]=='S'||mat[i][jj][k]=='E')
            {
              mat[i][jj][k]='#';
            }
          }
        }
        if(mat[i][j][k]=='2')
        {
          for(int ii=i+1;ii<n;ii++)
          {
            if(mat[ii][j][k]=='.'||mat[ii][j][k]=='S'||mat[ii][j][k]=='E')
            {
              mat[ii][j][k]='#';
            }
          }
        }
        if(mat[i][j][k]=='3')
        {
          for(int jj=j-1;jj>=0;jj--)
          {
            if(mat[i][jj][k]=='.'||mat[i][jj][k]=='S'||mat[i][jj][k]=='E')
            {
              mat[i][jj][k]='#';
            }
          }
        }
        if(mat[i][j][k]=='4')
        {
          for(int ii=i-1;ii>=0;ii--)
          {
            if(mat[ii][j][k]=='.'||mat[ii][j][k]=='S'||mat[ii][j][k]=='E')
            {
              mat[ii][j][k]='#';
            }
          }
        }
      }
    }
  }
  queue<int> qi;
  queue<int> qj;
  queue<int> qs;
  queue<int> qn;
  qi.push(ei);
  qj.push(ej);
  qs.push(0);
  qn.push(0);
  if(mat[ei][ej][0]=='#')
    return -1;
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
    if(dist[topi][topj][topn]>tops)
      dist[topi][topj][topn]=tops;
    int nov=topn+1;
    if(nov==4)
      nov=0;
    if(topi+1<n&&(mat[topi+1][topj][nov]=='.'||mat[topi+1][topj][nov]=='S'||mat[topi+1][topj][nov]=='E')&&dist[topi+1][topj][nov]>tops+1)
    {
      dist[topi+1][topj][nov]=tops+1;
      qi.push(topi+1);
      qj.push(topj);
      qs.push(tops+1);
      qn.push(nov);
    }
    if(topj-1>=0&&(mat[topi][topj-1][nov]=='.'||mat[topi][topj-1][nov]=='S'||mat[topi][topj-1][nov]=='E')&&dist[topi][topj-1][nov]>tops+1)
    {
      dist[topi][topj-1][nov]=tops+1;
      qi.push(topi);
      qj.push(topj-1);
      qs.push(tops+1);
      qn.push(nov);
    }
    if(topj+1<m&&(mat[topi][topj+1][nov]=='.'||mat[topi][topj+1][nov]=='S'||mat[topi][topj+1][nov]=='E')&&dist[topi][topj+1][nov]>tops+1)
    {
      dist[topi][topj+1][nov]=tops+1;
      qi.push(topi);
      qj.push(topj+1);
      qs.push(tops+1);
      qn.push(nov);
    }
    if(topi-1>=0&&(mat[topi-1][topj][nov]=='.'||mat[topi-1][topj][nov]=='S'||mat[topi-1][topj][nov]=='E')&&dist[topi-1][topj][nov]>tops+1)
    {
      dist[topi-1][topj][nov]=tops+1;
      qi.push(topi-1);
      qj.push(topj);
      qs.push(tops+1);
      qn.push(nov);
    }
  }
  int mini=1e9;
  for(int i=0;i<4;i++)
    mini=min(mini,dist[pi][pj][i]);
  if(mini==1e9)
    return -1;
  else
    return mini;
  }
};