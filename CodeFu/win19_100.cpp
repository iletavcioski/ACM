#include <string>
#include <vector>
using namespace std;

class SkiDay
{
  public:
    int getNumberOfYoungSkiers(int N, int M)
    {
        for(int i = 0; i < N; i++) {
            if((i*750 + (N-i)*1000) == M) {
                return i;
            }
        }
        return 0;
    }
};