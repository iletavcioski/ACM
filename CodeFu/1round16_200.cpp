#include <string>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

class PopularTweets
{
  public:
    string mostPopular(vector<string> tweets)
    {
       map<string,int> m;
       for(int i=0;i<tweets.size();i++)
      {
          for(int j=0;j<tweets[i].size();j++)
         {
                if(tweets[i][j]!='#')
                  {
                        if(tweets[i][j]>=60&&tweets[i][j]<=90)
                           tweets[i][j]+=32;
                 }   
         }
      }
      for(int i=0;i<tweets.size();i++)
      {
             string ss="";
set<string> sss;
             for(int j=0;j<tweets[i].size();j++)
            {
                  if(tweets[i][j]!=' ')
                 ss+=tweets[i][j];
                  else
                   {
                       
          if(ss[0]=='#')
sss.insert(ss);

ss="";
                   }
            }
if(ss[0]=='#')
         sss.insert(ss);
    for(set<string>::iterator it=sss.begin();it!=sss.end();it++)
       m[*it]++;
      
             
       }
       int maxi=0;
string maxx;
for(map<string,int>::iterator itt=m.begin();itt!=m.end();itt++)
{
    if(maxi<itt->second)
     {
      maxi=itt->second;
maxx=itt->first;
      }
    if(maxi==itt->second)
{
     maxx=min(maxx,itt->first);
}
}
      return maxx;
  }
};