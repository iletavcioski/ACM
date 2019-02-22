#include <string>
#include <vector>
using namespace std;

class SpikingSensor
{
  public:
    int getMedian(vector<int> values)
    {
      sort(values.begin(),values.end());
       int k=values.size();
       if(k%2==1)
        return values[k/2];
       else
return (values[k/2-1]+values[k/2]+1)/2;

      return 0;
  }
};