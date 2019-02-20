#include <string>
#include <vector>
using namespace std;

class GunScratch
{
  public:
    int matches(vector<string> bullets, string bullet)
    {
        string b=bullet;
        vector<string> v=bullets;
        int kraj=-1;
        for(int i=0;i<v.size();i++)
        {
            string s=v[i];
            int n=s.size();
            for(int j=0;j<n;j++)
            {
                string ss="";
                int k=j;
                while(1)
                {
                    if(ss.size()==n){
                    break;
                    }
                    ss+=s[k];
                    k++;
                    if(k==n)
                        k=0;
                    if(k==j)
                        break;
                }
                if(ss==b)
                {
                    kraj=i;
                    break;
                }
            }
            if(kraj!=-1)
                break;
        }
      return kraj;
  }
};
