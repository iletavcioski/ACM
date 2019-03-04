#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > vec;
    vector<vector<pair<int,int> > > v(n+1,vec);
    vector<int> vc(n,0);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        vc[b]++;
        int d;
        if (a > b)
            d = b + n - a;
        else
            d=b-a;
        v[a].push_back(make_pair(d,b));
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    for (int i = 0; i < n; i++) {
        int br = 0;
       for (int j = 0; j < n; j++)
       {
           int a = i, b= j,c;
           if (v[j].size()>0) {
               c = v[j][v[j].size()-1].second;
           }
           int d = -1;
           if (a > b)
               d = b + n - a;
           else
               d=b-a;
           int g = -1;
           if (b > c)
               g = c + n - b;
           else
               g=c-b;
               if(d!=-1 && g != -1) {
           br = max(br, (d + n*((int)v[j].size()-1) + g));
               }
       }
       cout<<br<<" ";
    }
    cout<<endl;

}