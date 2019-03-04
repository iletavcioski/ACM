#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int vis[51][51];
int vis2[51][51];
int main()
{
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	int z,c;
	cin>>z>>c;
	x--;
	y--;
	z--;
	c--;
	queue<int> qi,qj;
	char mat[n+1][n+1];
	int p[4] = {0,0,-1,1};
	int m[4] = {-1,1,0,0};
	for (int i = 0; i <n;i++) {
		for (int j = 0; j < n; j++)
		{
			cin>>mat[i][j];
			vis[i][j] = 0;
			vis2[i][j] = 0;
		}
	}
	qi.push(x);
	qj.push(y);
	vis[x][y] = 1;
	while(!qi.empty()) 
	{
		int topi = qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		for (int i = 0 ; i < 4; i++) {
			int a = topi+p[i];
			int b= topj+m[i];
			//cout<<a<<" "<<b<<endl;
			if (a >= 0 && a < n && b >= 0 && b < n) {
			    
				if (vis[a][b] == 0 && mat[a][b] == '0')
				{
				    //cout<<1<<endl;
					vis[a][b]=1;
					qi.push(a);
					qj.push(b);
				}
			}
		}
	}

	qi.push(z);
	qj.push(c);
	vis2[z][c] = 2;
	while(!qi.empty()) 
	{
		int topi = qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		for (int i = 0 ; i < 4; i++) {
			int a = topi+p[i];
			int b= topj+m[i];
			if (a >= 0 && a < n && b >= 0 && b < n) {
				if (vis2[a][b] == 0 && mat[a][b]=='0')
				{
					vis2[a][b]=2;
					qi.push(a);
					qj.push(b);
				}
			}
		}
	}
	int maxi = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				for (int k = 0; k < n; k++) {
				if (vis[i][j] == 1 && vis2[l][k] == 2) {
					maxi=min(maxi,((i-l)*(i-l)) + ((j-k)*(j-k)));

				}
			}
			}
		}
	}

	cout<<maxi<<endl;
	return 0;
}