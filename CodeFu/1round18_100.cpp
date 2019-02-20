#include <string>
#include <vector>
using namespace std;
typedef long long ll;
class RGB
{
  public:
    ll countWays(ll N)
    {
	ll brojac=0;
		for(ll i=0;i<=N;i++)
	{
	brojac+=((N-i)+1);
	}
      return brojac;
  }
};
