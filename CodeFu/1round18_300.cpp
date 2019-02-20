#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Squares
{
  public:
    int findMax(vector<int> x, vector<int> y)
    {
		
        static bool mat[51][51][51][51];
        for(int i=0;i<51;i++)
        {
            for(int j=i+1;j<51;j++)
            {
                for(int k=j+1;k<51;k++)
                {
                    for(int l=k+1;l<51;l++)
                    {
                        mat[i][j][k][l]=0;
                    }
                }
            } 
        }
        int n=x.size();
        int brojac=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        
                        vector<int> vk;
                        vk.push_back(i);
                        vk.push_back(j);
                        vk.push_back(k);
                        vk.push_back(l);
                        //sort(vk.begin(),vk.end());
                        //if(s.size()==4)
                        //{
                            if(mat[vk[0]][vk[1]][vk[2]][vk[3]]==0)
                            {
                                vector<pair<int,int> > v;
                                v.push_back(make_pair(x[i],y[i]));
                                v.push_back(make_pair(x[l],y[l]));
                                v.push_back(make_pair(x[k],y[k]));
                                v.push_back(make_pair(x[j],y[j]));
								sort(v.begin(),v.end());
                                
									
                                        int a=((abs(v[1].second-v[0].second)*abs(v[1].second-v[0].second))+(abs(v[1].first-v[0].first)*abs(v[1].first-v[0].first)));
                                        int b=((abs(v[2].second-v[0].second)*abs(v[2].second-v[0].second))+(abs(v[2].first-v[0].first)*abs(v[2].first-v[0].first)));
                                        int c=((abs(v[1].second-v[3].second)*abs(v[1].second-v[3].second))+(abs(v[1].first-v[3].first)*abs(v[1].first-v[3].first)));
                                        int d=((abs(v[2].second-v[3].second)*abs(v[2].second-v[3].second))+(abs(v[2].first-v[3].first)*abs(v[2].first-v[3].first)));
                                        int e=((abs(v[0].second-v[3].second)*abs(v[0].second-v[3].second))+(abs(v[0].first-v[3].first)*abs(v[0].first-v[3].first)));
                                        int f=((abs(v[2].second-v[1].second)*abs(v[2].second-v[1].second))+(abs(v[2].first-v[1].first)*abs(v[2].first-v[1].first)));                                        set<int> ss;
                                        ss.insert(a);
                                        ss.insert(b);
                                        ss.insert(c);
                                        ss.insert(d);
                                        if(ss.size()==1&&e==f)
                                        {
                                            brojac++;
                                            mat[vk[0]][vk[1]][vk[2]][vk[3]]=1;
                                        }
                                    
                                
                            
                        }
                    }
                }
            }
        }
      return brojac;
  }
};