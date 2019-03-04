#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double v[n];
    int pol = n/2;
    if (n%2)
        pol++;
    for (int i = 0;i < n; i++)
        cin>>v[i];
    for (int i = -1000; i <= 1000; i++) {
        if (i == 0)
            continue;
        int br =0;
        for (int j = 0; j < n; j++) {
            double a = v[j]/((double)i);
            if (a > ((double)0))
                br++;
        }
        if (br >=pol) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}