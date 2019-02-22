#include <string>
#include <vector>
using namespace std;

class AnnoyingColleague
{
  public:
    string getColleague(vector<string> names, vector<string> availability)
    {
     string kraj="";
     bool k=false;
       for(int i=0;i<names.size();i++)
       {
           if(availability[i]=="available")
           {
    k=true;
                 if(kraj=="")
              kraj=names[i];
else
                 kraj=min(kraj,names[i]);
             }
       }
     if(!k)
      return "none";
else 
return kraj;
  }
};