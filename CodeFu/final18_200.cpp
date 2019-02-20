#include <string>
//#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class FlippingCards
{
  public:
    int transform(string cards)
    {
	int dp[(1<<20)+2];
int broj=1;
int brojac=0;
int n=cards.size();
	for(int i=cards.size()-1;i>=0;i--)
{
if(cards[i]=='U')
brojac+=broj;
broj*=2;
}
for(int i=0;i<(1<<20);i++)
dp[i]=1e9;
dp[brojac]=0;
queue<int> qi;
qi.push(brojac);
while(!qi.empty())
    {
    int bi=qi.front();
    qi.pop();
    //cout<<bi<<endl;
    int bit=bi;
    for(int i=1;i<n-1;i++)
    {
        bit=bi;
    int a=i-1,b=i,c=i+1;
    if(bit&(1<<a))
    bit^=(1<<a);
    else
        bit|=(1<<a);
    if(bit&(1<<b))
    bit^=(1<<b);
    else
        bit|=(1<<b);
        if(bit&(1<<c))
    bit^=(1<<c);
    else
        bit|=(1<<c);
       // cout<<bit<<endl;
        if(dp[bit]>dp[bi]+1)
        {

            qi.push(bit);
            dp[bit]=dp[bi]+1;
        }
    }
    }
    if(dp[0]==1e9)
        return -1;
      return dp[0];
  }
};