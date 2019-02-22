#include <string>
#include <vector>
#include <map>
#include<queue>
#include<algorithm>
using namespace std;

class PalindromicTree
{
  public:
    int getMinimumInsertions(vector<string> connections, string nodeValues)
    {
map<char,int>mm;
int brojac=0;
	vector<int> vi;
    vector<vector<int> > v;
	v.insert(v.begin(),101,vi);
  for(int i=0;i<connections.size();i++)
{
int bb;
if(connections[i][0]!=' '&&connections[i][1]!=' ')
bb=(connections[i][0]-'0')*10+(connections[i][1]-'0');
else
bb=connections[i][0]-'0';
for(int j=2;j<connections[i].size()-1;j++)
{
    if(connections[i][j]!=' '&&connections[i][j+1]!=' ')
        v[bb].push_back((connections[i][j]-'0')*10+(connections[i][j+1]-'0'));
    if(connections[i][j]!=' '&&connections[i][j-1]==' '&&connections[i][j+1]==' ')
        v[bb].push_back(connections[i][j]-'0');
}
if(connections[i][connections[i].size()-1]!=' '&&connections[i][connections[i].size()-2]==' ')
v[bb].push_back(connections[i][connections[i].size()-1]-'0');
}
queue<int>qi;
queue<int>qs;
qi.push(0);
qs.push(0);
int i=0;
string ss="";
while(!qi.empty())
{
int topi=qi.front();
qi.pop();
int tops=qs.front();
qs.pop();

if(tops==i)
ss+=nodeValues[topi];
else
{
i++;
int np=0;
map<char,int> m;
for(int ii=0;ii<ss.size();ii++)
{
	m[ss[ii]]++;
}
for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
{
int a=it->second;
if(a%2!=0)
np++;

}
if(np>1)
brojac+=np-1;
ss="";
ss+=nodeValues[topi];
}
for(int ii=0;ii<v[topi].size();ii++)
{
qi.push(v[topi][ii]);
qs.push(tops+1);
}


}
i++;
int np=0;
map<char,int> m;
for(int ii=0;ii<ss.size();ii++)
{
	m[ss[ii]]++;
}
for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
{
int a=it->second;
if(a%2!=0)
np++;
}
if(np>1)
brojac+=np-1;
return brojac;
  }
};