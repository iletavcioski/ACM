#include <iostream>
using namespace std;
int dist[65][65];
int main()
{
	char c1,c2;
	for(int i=0;i<64;i++) 
	{
		for(int j=0;j<64;j++) 
			dist[i][j]=1e9;
	}
	for(int i=0;i<64;i++)
	{
		dist[i][i]=0;
		if(i/8<7&&(i%8)<6) 
			dist[i][i+10]=dist[i+10][i]=1;
		if(i/8<6&&(i%8)<7) 
			dist[i][i+17]=dist[i+17][i]=1;
		if(i/8<6&&(i%8)>0) 
			dist[i][i+15]=dist[i+15][i]=1;
		if(i/8<7&&(i%8)>1) 
			dist[i][i+6]=dist[i+6][i]=1;
	}
	for(int k=0;k<64;k++)
	{
		for(int i=0;i<64;i++)
		{
			for(int j=0;j<64;j++)
			{
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int t;
	cin>>t;
	int a,b;
	while(t--)
	{
		do{
			c1=getchar();
		}while(c1==' '||c1=='\n'||c1=='\r');
		cin>>a;
		do{
			c2 = getchar();
		}while(c2==' '||c2=='\n'||c2=='\r');
		cin>>b;
		cout<<dist[(a-1)*8+((int)c1-'a')][(b-1)*8+((int)c2-'a')]<<endl;
	}
	return 0;
} 