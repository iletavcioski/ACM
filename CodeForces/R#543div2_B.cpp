#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin>>n;
	vector<bool> v(200001, 0);
	vector<int> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin>>a;
		v[a] = true;
		k.push_back(a);
	}
	int maxi = 0;
	for (int i = 1; i <= 200000; i++) {
		int br = 0;
		for (int j = 0; j < k.size(); j++) {
		    if (i >= k[j]) {
    			if((i - k[j]) != k[j]) {
    				if (v[i - k[j]] == true)
    					br++;
    			}
		    }
		}
		maxi = max(maxi,br/2);
	}
	cout<<maxi<<endl;
	return 0;
}