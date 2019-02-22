#include <string>
#include <vector>
#include <queue>
using namespace std;

class OrderedDigits
{
  public:
  	int steps (int a, int b) {
  		int br = 0;
  		int a1 = a;
      			int mini = 100;
      			while (a != b) {
      				a++;
      				br++;
      				if (a == 10)
      					a = 0;
      				if (a == b)
      					break;
      			}
      			mini = min(mini, br);
      			br = 0;
      			a = a1;
      			while (a != b)
      			{
      				a--;
      				br++;
      				if (a == -1)
      					a = 9;
      				if (a == b)
      					break;
      			}
      			mini=min(mini,br);
      			return mini;
  	}
    int operations(string number)
    {
      vector<int> v;
      for (int i = 0; i < number.size(); i++) {
      	v.push_back(number[i] - '0');
      }
      int dp[301][11];
      for (int i = 0; i <= 300; i++) {
      	for (int j = 0; j <= 9; j++) {
      		dp[i][j] = 1000000;
      	}
      }

      for (int i = 0; i < v.size(); i++) {
      	if (i == 0) {
      		for (int j = 0; j <= 9; j++) {
      			dp[i][j] = steps(v[i], j);
      		}
      	}
      	else {
      		for (int k = 0; k <=9;k++) {
      		for (int j = k; j>=0; j--) {
      			dp[i][k] = min(dp[i][k], dp[i-1][j] + steps(v[i],k));
      		}
      	}
      	}
      }
      int mini = 1000000;
      for (int i = 0; i <= 9; i++) {
      	mini = min(mini, dp[v.size()-1][i]);
      }
      return mini;
  }
};