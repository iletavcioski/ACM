#include <string>
#include <vector>
using namespace std;

class BeautifulString
{
  public:
    int remove(string string)
    {
    	int mini = 1000;
      for (int i = 0; i < string.size(); i++) {
      	for (int j = i + 1; j < string.size(); j++) {
      		if (string[i] == string[j]) {
      			mini = min(mini, j - i - 1);
      		}
      	}
      }
      if (mini == 1000)
      	return -1;
      else
      	return mini;
  }
};