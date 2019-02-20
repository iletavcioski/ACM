#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MergeNames
{
  public:
    string merge(vector<string> names)
    {
        vector<string> v=names;
        vector<string> v1;
        while((int)v.size()>1)
        {
            sort(v.begin(),v.end());
            int i=0,j=v.size()-1;
            while(i<=j)
            {
                if(i==j)
                    v1.push_back(v[i]);
                else
                    v1.push_back(v[j]+v[i]);
                i++;
                j--;
            }
            v.clear();
            v=v1;
            v1.clear();
        }
      return v[0];
  }
};