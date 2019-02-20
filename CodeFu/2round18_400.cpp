#include<string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

class MovingTime
{
  public:
    const double pi=3.14159265359;
    
    string maximizeRouterSpeed(string a, string b)
    {
        vector<int> v(10,1);
        for(int i=1;i<10;i++)
        {
            v[i]=v[i-1]*10;
        }
        string b1="";
        string b2="";
        string d1="";
        string d2="";
        bool cc=false;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='.')
                cc=true;
            else
            {
                if(!cc)
                    b1+=a[i];
                if(cc)
                    d1+=a[i];
            }
        }
        cc=false;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]=='.')
                cc=true;
            else
            {
                if(!cc)
                    b2+=b[i];
                if(cc)
                    d2+=b[i];
            }
        }
        int bg=0;
        double dd1=0;
        double k1=0,k2=0;
        for(int i=d1.size()-1;i>=0;i--)
        {
            dd1+=((d1[i]-'0')*v[bg]);
            bg++;
        }
        k1=dd1/(double)v[bg];
        bg=0;
        double dd2=0;
        for(int i=d2.size()-1;i>=0;i--)
        {
            dd2+=((d2[i]-'0')*v[bg]);
            bg++;
        }
        k2=dd2/(double)v[bg];
        bg=0;
        double bb1=0;
        for(int i=b1.size()-1;i>=0;i--)
        {
            bb1+=((b1[i]-'0')*v[bg]);
            bg++;
        }
        k1+=bb1;
        bg=0;
        double bb2=0;
        for(int i=b2.size()-1;i>=0;i--)
        {
            bb2+=((b2[i]-'0')*v[bg]);
            bg++;
        }
        k2+=bb2;
        double maxx=0.0;
        double maxi=1000000000;
        for(double i=0.00;i<=200;i+=(0.0001))
        {
            vector<double> vk;
            double k3=i;
            vk.push_back(k1);
            vk.push_back(k2);
            vk.push_back(k3);
            sort(vk.begin(),vk.end());
            if(vk[2]<(vk[0]+vk[1]))
            {
                
                double area;
                double polu;
                polu=(k1+k2+k3)/2.00;
                 double brojac=(polu*(double)abs(polu-k1)*(double)abs(polu-k2)*(double)abs(polu-k3));
                area=sqrt(brojac);
                double prvo=0.0;
                prvo=area/polu;
                double vtoro=0.0;
                vtoro=(double)(k1*k2*k3)/(double)(4.00*area);
                double broj=(vtoro-prvo);
                double vv=0.0;
                double pp=0.0;
                vv=vtoro*vtoro*pi;
                pp=prvo*prvo*pi;
                broj=vv-pp;
                if(broj<maxi)
                {
                    maxi=broj;
                    maxx=k3;
                }
            }
        }
        double mini=maxx;
mini+=0.005;
		mini*=100;
		stringstream ss;
		ss<<mini;
		string str;
		str=ss.str();
		string kraj="";
		 for(int i=0;i<str.size();i++)
		 {
			 if(str[i]!='.')
			 kraj+=str[i];
			 else
				 break;
		 }
		 kraj.insert((kraj.end()-2),'.');
      return kraj;
  }
};