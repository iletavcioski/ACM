#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <sstream>
#include <cstring>
using namespace std;

class Kermit
{
  public:
    string swim(int R, vector<int> X, vector<int> Y)
    {
          queue<int> qi;
		queue<int> qj;
		queue<double> qs;
         qi.push(0);
		 qj.push(-1);
		 qs.push(0.0);
		vector<vector<double> > visited;
		 vector<double> vecc(101,999999.9);
		 visited.insert(visited.begin(),101,vecc);
		 //double visited[100][100];
		 //memset(visited,999999.9,sizeof(visited));
		 visited[0][0]=0.0;

		 while(!qi.empty())
		 {
			 int topi=qi.front();
			 int topj=qj.front();
			 double tops=qs.front();
			 qi.pop();
				 qj.pop();
				 qs.pop();
				 if(((R-topi)<=10)&&((tops+(R-topi))<(visited[R][R]-0.000001)))
				 {
					 visited[R][R]=(tops+(R-topi));
				 }
				 for(int i=0;i<X.size();i++)
				 {
					 if(topj==-1)
					 {
						 double distance=X[i];
						 if(distance!=0.00000){
							 if(distance<10.0000001){
						 if(((tops+distance)<(visited[X[i]][Y[i]]-0.0000001)))
						 {
							 
							 visited[X[i]][Y[i]]=(tops+distance);
							 qi.push(X[i]);
							 qj.push(Y[i]);
							 qs.push((tops+distance));
						 }
							 }
						 }
					 }
					 else
					 {
						 double d=abs(X[i]-topi);
						 double d1=abs(Y[i]-topj);
						 double dd=(d*d)+(d1*d1);
						 double distance=sqrt(dd);
						 const double aa=10;
						 if(distance<10.0000000001){
						 if(distance!=0.00000000000){
						 if(((tops+distance)<(visited[X[i]][Y[i]]+0.000001)))
						 {
							 visited[X[i]][Y[i]]=tops+distance;
							 qi.push(X[i]);
							 qj.push(Y[i]);
							 qs.push(tops+distance);
						 }
						 }
						 }
					 }
					 
					 
				 }
		 }

		 double mini=visited[R][R];
		 if(mini==999999.9)
		 {
			 return "poor kermit";
			 //return 0;
		 }
		mini+=0.005;
		mini*=100;
		stringstream ss;
		ss<<mini;
		string str;
		str=ss.str();
		string kraj="";
		 for(int i=0;i<str.size();i++)
		 {
			 if(str[i]!='.')
			 kraj+=str[i];
			 else
				 break;
		 }
		 kraj.insert((kraj.end()-2),'.');
      return kraj;
  }
};