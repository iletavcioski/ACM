#include <string>
#include <vector>
using namespace std;

class SpaceTravel
{
  public:
    int findTimestep(vector<string> ka, vector<string> kr)
    {
        int n = ka.size();
        int m = kr.size();
        int poc = 0;
        while (poc < 5000) {
            int x = poc;
            x %= n;
            int y = 0;
            int najde = 0;
            while (y < m && najde == 0) {
                if (ka[x] == "Eset" && ka[x] == kr[y]) {
                    najde = 1;
                    break;
                }
                x++;
                y++;
                if (x == n) x -= n;
            }
            if (najde == 1) return poc + 1;
            poc++;
        }
        return 0;
    }
};