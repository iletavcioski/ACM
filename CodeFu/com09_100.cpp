#include <string>
#include <vector>
using namespace std;

class MemoryLane
{
  public:
    string valentineWish(vector<int> lane)
    {
      for(int i=1;i<lane.size();i++)
     {
         if(lane[i]==lane[i-1]){
       bool c=false;
          for(int j=i;j<lane.size();j++)
            {
             if(i!=j)
              {
                   if(lane[j]!=lane[i])
                     {
                      swap(lane[i],lane[j]);
                    c=true;
                    break;
                        }
              }
           }
             if(!c)
              return "J.K. will be spending his Valentine's Day alone :(";
         }
      }
      return "Love is in the air! <3";
  }
};