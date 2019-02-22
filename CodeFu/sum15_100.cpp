#include <string>
#include <vector>
using namespace std;

class FaultyCompressor
{
  public:
    string compressMe(string input)
    {
      string s;
	s=input;
char b=s[0];
   string kraj="";
   vector<string> vec;
   kraj+=b;
if(s.size()==1)
{
string krajss="";
krajss+=s[0];
krajss+='1';
return krajss;
}
    for(int i=1;i<s.size();i++)
	{
		if(s[i]==b)
		{
			kraj+=b;
                     
		}
		else
		{
			vec.push_back(kraj);
			b=s[i];
			kraj="";
			kraj+=b;
		}
		if(i==s.size()-1)
		{
			vec.push_back(kraj);
		}
	}
	 string krajs="";
	 for(int i=0;i<vec.size();i++)
	 {
		 if(vec[i].size()==1)
		 {
			 krajs+=vec[i][0];
                      krajs+='1';
		 }
		 else
		 {
			 krajs+=vec[i][0];
			 int n=vec[i].size();
			 vector<char>v;
			 while(n>0)
			 {
				 char d=n%10;
				 v.push_back(d+'0');
				 n/=10;
			 }
			 reverse(v.begin(),v.end());
			 for(int i=0;i<v.size();i++)
			 {
				 krajs+=v[i];
			 }
		 }
	 }
	 return krajs;
  }
};