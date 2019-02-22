#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Traveler
{
  public:
    string closest(vector<string> connections)
    {

    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(),1500,vec);
int n=0;
    for(int i=0;i<connections.size();i++)
    {
        
        string k=connections[i];
        string s1="",s2="";
        bool cc=false;

        for(int j=0;j<k.size();j++)
        {
            if(k[j]!='-')
            {
                if(!cc)
                    s1+=k[j];
                else
                    s2+=k[j];
            }
            else 
                cc=true;
                
            
            
        }
        int broj=1;
        int br1=0,br2=0;
        for(int j=s1.size()-1;j>=0;j--)
        {
         br1+=(s1[j]-'0')*broj;
         broj*=10; 
        }
        broj=1;
        for(int j=s2.size()-1;j>=0;j--)
        {
         br2+=(s2[j]-'0')*broj;
         broj*=10; 
        }
n=max(n,max(br1,br2));
        v[br1].push_back(br2);
v[br2].push_back(br1);
   
    }
    queue<int> qi;
    queue<int> qs;
    vector<int> vis(1500,1e9);
    vector<int> kraj(1500,0);
    string ss="";
    vis[0]=0;
    qi.push(0);
    qs.push(0);
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int tops=qs.front();
        qs.pop();
        for(int i=0;i<v[topi].size();i++)
        {
            if(vis[v[topi][i]]>tops+1)
            {
                qi.push(v[topi][i]);
                qs.push(tops+1);
                vis[v[topi][i]]=tops+1;
            }
        }
        
    }
    bool kk=false;
    for(int i=0;i<=n;i++)
    {
        if(vis[i]!=1e9)
        kraj[vis[i]]++;
            else 
            kk=true;
    }
    for(int i=1;i<kraj.size();i++)
    {
        string s1="";
if(kraj[i]==0)
break;
        while(kraj[i]>0)
        {
            s1+=(kraj[i]%10+'0');
            kraj[i]/=10;
        }
        reverse(s1.begin(),s1.end());
        if(i>1)
            ss+=',';
        ss+=s1;
    }
    if(kk)
        ss+=",:(";
    return ss;
  }
};