#include <string>
#include <vector>
using namespace std;

class Sniper
{
  public:
    int getMaximum(vector<string> map)
    {
      int a=map[0].size();
string ss="";
for(int i=0;i<a;i++)
ss+='.';
vector<string> v;
 int brojac=0;
 string s;

       for(int i=0;i<map.size();i++)
       {
		   string ssss=map[i];
            for(int j=0;j<ssss.size();j++)
            {
               s=ss;
               if(ssss[j]=='+')
               {
                 s[j]='+' ;
                v.push_back(s);
               }
        s=ss;
			   if(ssss[j]=='-')
			   {
				   s[j]='-';
				   v.push_back(s);
			   }
            }
       }
int maxi=0;
      for(int i=0;i<=100;i++)
        {

           if(i!=0)
{
    for(int ii=0;ii<v.size();ii++)
    {
           for(int jj=0;jj<v[ii].size();jj++)
          {
                if(v[ii][jj]=='+')
                       {
                           v[ii][jj]='.';
                            if(jj==v[ii].size()-1)
                                {
                                      
                                        v[ii][jj-1]='-';
                                }
                               else
                                v[ii][jj+1]='+';
break;
                        }
                  if(v[ii][jj]=='-')
                       {
                            v[ii][jj]='.';
                            if(jj==0)
                                {
                                      
                                        v[ii][jj+1]='+';
                                }
                               else
                                v[ii][jj-1]='-';
break;
                        }
          
          }
    }
}
		    brojac=0;
    for(int ii=0;ii<v[0].size();ii++)
    {
		int broj=0;
           for(int jj=0;jj<v.size();jj++)
           {
                if(v[jj][ii]!='.')
                broj++;
             }
		   brojac=max(brojac,broj);
    }
maxi=max(maxi,brojac);
         }
      return maxi;
  }
};