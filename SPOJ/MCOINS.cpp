#include <iostream>
using namespace std;
bool dp[1000001];
int main()
{
    int k,l;
    cin>>k>>l;
    dp[0]=false;
    for(int i=1;i<=1000000;i++)
    {
        int br=0;
        int kk=1;
        if(i-k>=0)
        {
            if(dp[i-k]==false)
                br++;
            kk++;
        }
        if(i-l>=0)
        {
            if(dp[i-l]==false)
                br++;
            kk++;
        }
        if(dp[i-1]==false)
            br++;
        if(br)
            dp[i]=true;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        if(dp[a])
            cout<<"A";
        else
            cout<<"B";
    }
    cout<<endl;
    return 0;
}