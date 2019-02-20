#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
class PrimeFactors
{
  public:
    string count(string A, string B)
    {

	ll a=0;
	ll b=0;
	ll br=1;
	for(int i=A.size()-1;i>=0;i--)
    {
        a+=(ll)((A[i]-'0')*br);
        br*=(ll)10;

    }
    br=1;
    for(int i=B.size()-1;i>=0;i--)
    {
        b+=(ll)((B[i]-'0')*br);
        br*=10;
    }
    static bool er[10000001];
    for(int i=2;i<=10000000;i++)
    {
        er[i]=true;
    }
    for(int i=2;i<=10000000;i++)
    {
        if(er[i]){
            for(int j=i+i;j<=10000000;j+=i)
            er[j]=false;
        }
    }
    ll brojac=0;

    for(int i=2;i<=10000000;i++)
    {
        if(er[i])
        {

            ll l=2;
            ll r=0;
            ll mno=(ll)i;
            ll brojce=(ll)i;

            while(1)
            {
                if(brojce<=b&&brojce>=0)
                    r++;
                else
                    break;
                brojce*=mno;
            }

            ll mini=1e9;
            ll maxi=-1;
            ll l1=l;
            ll r1=r;
            while(l<=r)
            {

                ll mid=(l+r)/2;
                if((pow(mno,mid))>=a)
                    mini=min(mini,mid),r=mid-1;
                else
                    l=mid+1;
            }
            while(l1<=r1)
            {

                ll mid=(l1+r1)/2;
                if((pow(mno,mid))<=b)
                    maxi=max(maxi,mid),l1=mid+1;
                else
                    r1=mid-1;
            }

            if(maxi!=-1&&mini!=1e9)
            {

            brojac+=(max((ll)0,(ll)(maxi-mini+1)));
            }
        }

    }
    string kraj="";
    if(brojac==0)
        kraj="0";
    while(brojac>0)
    {
        kraj+=((brojac%10)+'0');
        brojac/=10;
    }
    reverse(kraj.begin(),kraj.end());
      return kraj;
  }
};