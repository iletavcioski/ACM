#include <string>
#include <vector>
using namespace std;

class LeapYear
{
  public:
    string isLeapYear(int year)
    {
     if(year%400==0||(year%4==0&&year%100!=0))
      return "YES";
else
return "NO";
  }
};