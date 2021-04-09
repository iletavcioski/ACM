#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v1, v2;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    int brojac=0;
    int i = n-1, j = m-1;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while (i>=0&&j>=0) {
        if (v2[j] >= v1[i] - k && v2[j] <= v1[i] + k) {
            i--;
            j--;
            brojac++;
        }
        else if(v2[j] > v1[i] + k)
            j--;
        else if(v2[j] < v1[i] - k)
            i--;
    }
    cout<<brojac<<endl;
    return 0;
}
