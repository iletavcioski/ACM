#include <string>
#include <vector>
#include<map>
#include<queue>
using namespace std;

class BannedWord
{
  public:
    int minRemove(string word, string bannedWord)
    {
     queue<string> qi;
      map<string,bool> m;
      queue<int> qs;
	  qi.push(word);
	  qs.push(0);
int maxi=1e8;
       while(!qi.empty())
       {
          string topi=qi.front();
			qi.pop();
			int tops=qs.front();
		qs.pop();
		if(topi.size()<bannedWord.size())
		{
			maxi=min(maxi,tops);
continue;
		}
		if(topi.size()==bannedWord.size())
		{
			if(topi!=bannedWord)
			{maxi=min(maxi,tops);
continue;
			}
		}

		int index=topi.find(bannedWord);
		if(index==-1)
		{
			maxi=min(maxi,tops);
continue;
		}
		for(int i=index;i<index+bannedWord.size();i++)
		{
			string ss="";
			for(int j=0;j<topi.size();j++)
			{
				if(i!=j)
					ss+=topi[j];
			}
			if(!m[ss])
			{
				qi.push(ss);
				qs.push(tops+1);
				m[ss]=true;
			}
		
		}
       }
return maxi;
  }
};