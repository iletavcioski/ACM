#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,s,f,u,d;
    cin>>n>>s>>f>>u>>d;
    vector<int> v(n+3,1e9);
    queue<int> qi;
    queue<int> qs;
    qi.push(s);
    qs.push(0);
    v[s]=0;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int tops=qs.front();
        qs.pop();
        if(topi+u<=n&&v[topi+u]>tops+1)
        {
            v[topi+u]=tops+1;
            qi.push(topi+u);
            qs.push(tops+1);
        }
        if(topi-d>=1&&v[topi-d]>tops+1)
        {
            v[topi-d]=tops+1;
            qi.push(topi-d);
            qs.push(tops+1);
        }
    }
    if(v[f]!=1e9)
        cout<<v[f]<<endl;
    else
        cout<<"use the stairs"<<endl;
    return 0;
} 