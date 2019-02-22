#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GreedyEmployee
{

  public:
    int mostYen(int N, int K, vector<string> bill)
    {
    int suma=0;
vector<int> v;
vector<int> v1,v2;
    for(int i=0;i<N;i++)
    {
       
        v.push_back(bill[i][0]-'0');
v1.push_back(bill[i][1]-'0');
v2.push_back(bill[i][2]-'0');
     }
sort(v.begin(),v.end());
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
for(int i=0;i<v.size();i++)
{
if(K>0){
if(v[i]!=9){
v[i]=9;
suma+=900;
K--;
}
else
suma+=900;
}
else
suma+=v[i]*100;
}
for(int i=0;i<v1.size();i++)
{
if(K>0){
if(v1[i]!=9){
v1[i]=9;
suma+=90;
K--;
}
else
suma+=90;
}
else
suma+=v1[i]*10;
}
for(int i=0;i<v2.size();i++){
if(K>0){
if(v2[i]!=9){
v[i]=9;
suma+=9;
K--;
}
else
suma+=9;
}
else
suma+=v2[i];
}
return suma;
  }
};