#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int dp[101][101];
		int n=s1.size();
		int m=s2.size();
		for(int i=0;i<=s1.size();i++)
		{
			for(int j=0;j<=s2.size();j++)
			{
				int maxi=0;
				if(i>0)
					maxi=max(maxi,dp[i-1][j]);
				if(j>0)
					maxi=max(maxi,dp[i][j-1]);
				if(i>0&&j>0)
				{
					if(s1[i-1]==s2[j-1])
						maxi=max(maxi,dp[i-1][j-1]+1);
				}
				dp[i][j]=maxi;
			}
		}
		int ii=n;
		int jj=m;
		vector<int> v1,v2;
		string sk="";
		map<int,int> ima1,ima2;
		while(ii>0&&jj>0)
		{
			if(s1[ii-1]==s2[jj-1])
			{
				sk+=s1[ii-1];
				ima1[ii-1]=true;
				ima2[jj-1]=true;
				ii--;
				jj--;
			}
			else
			{
				if(dp[ii-1][jj]>dp[ii][jj-1])
					ii--;
				else
					jj--;
			}
		}
		reverse(sk.begin(),sk.end());
		ii=0,jj=0;
		string ss="";
		int poc=0;
		while(ii<n&&jj<m)
		{
			int k=ii,l=jj;
			for(;k<n&&!ima1[k];k++)
				ss+=s1[k];
			for(;l<m&&!ima2[l];l++)
				ss+=s2[l];
			while(k<n&&l<m&&ima1[k]&&ima2[l])
			{
				ss+=s1[k];
				k++;
				l++;
			}
			ii=k,jj=l;
		}
		while(ii<n)
		{
			ss+=s1[ii];
			ii++;
		}
		while(jj<m)
		{
			ss+=s2[jj];
			jj++;
		}
 
		cout<<ss<<endl;
	}
	return 0;
}