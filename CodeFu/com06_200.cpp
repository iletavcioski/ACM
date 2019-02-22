#include <string>
#include <vector>
using namespace std;

class DrinkingGame
{
  public:
    string solve(string vex, string mex, vector<string> transcripts)
    {
     int brojacv=0;
	int brojacm=0;
	int brojacvv=0;
	int brojacmm=0;
int brojacvkraj=0;
int brojacmkraj=0;
	for(int i=0;i<transcripts.size();i++)
	{
		int brojacv=0;
	int brojacm=0;
		for(int j=0;j<transcripts[i].size();j++)
		{
			for(int k=0;k<vex.size();k++)
			{
				if(vex[k]==transcripts[i][j])
				{
					brojacv++;
				}
			}
			for(int k=0;k<mex.size();k++)
			{
				if(mex[k]==transcripts[i][j])
				{
					brojacm++;
				}
			}
		}
		if(brojacv>brojacm)
			brojacvv+=brojacv+brojacm;
		else if(brojacm>brojacv)
			brojacmm+=brojacv+brojacm;
		else if(brojacv==brojacm)
		{
			brojacvv+=brojacv;
			brojacmm+=brojacm;
		}
brojacmkraj+=brojacm;
brojacvkraj+=brojacv;
	}
	if(brojacmm==brojacvv)
	{
		return "Tie";
	}
	if(brojacmm<brojacvv)
	{
		return "Vasko";
	}
	if(brojacmm>brojacvv)
	{
		return "Murat";
	}
  }
};