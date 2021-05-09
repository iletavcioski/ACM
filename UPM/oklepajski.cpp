#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;
struct node
{
    int l,r;
    int ind;
}queries[50001];
int v[100001];
int vv[100001];
int block=555;
int ans[100001];
bool compare (const node &x,const node &y)
{
    if(x.l/block!=y.l/block)
        return x.l/block<y.l/block;
    return x.r<y.r;
}
int brojac = 0;
void add(int x)
{
    vv[v[x]]++;
    if(vv[v[x]]==1)
        brojac++;
}
void remove(int x)
{
    vv[v[x]]--;
    if(vv[v[x]]==0)
        brojac--;
}
int n;
string izraz;
int q;
vector<int> mo;
vector<int> vis(100001, 0);
void read() {
    cin >> izraz;
    n = izraz.size();
}


void solve() {

    stack<pair<char, int> > ss;
    int br = 1;
    for (int j = 0; j < n; j++) {
            if (izraz[j] == '{' || izraz[j] == '(' || izraz[j] == '[' || izraz[j] == '<') {
                ss.push(mp(izraz[j], j));
            }
            else {
                if (ss.empty()) {
                    vis[j] = 0;
                    continue;
                }
                pair<char,int>  a = ss.top();
                if ((izraz[j] == '>' && a.f == '<') || (izraz[j] == ')' && a.f == '(') || (izraz[j] == '}' && a.f == '{') || (izraz[j] == ']' && a.f == '[')){
                    vis[a.s] = br;
                    vis[j] = br;
                    br++;
                    ss.pop();
                }
                else {
                    vis[a.s] = 0;
                    vis[j] = 0;
                    ss.pop();
                }
            }
        }
    /*
    for (int i = 0; i < n; i++) {
        cout << vis[i] << " ";
    }
    cout << endl;
     */
    for (int i = 0; i < n; i++) {
        v[i] = vis[i];
    }
   // cout << endl;

    int currL=0,currR=0;
    int q;
    cin >> q;
    string res = "";
    for (int i = 0; i < q; i++)
        res += '0';
    for(int i=0;i<q;i++)
    {
        cin >> queries[i].l;
        cin >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].ind = i;
    }
    sort(queries,queries+q,compare);
    brojac=0;

    for(int i=0;i<q;i++)
    {
        int L=queries[i].l;
        int R=queries[i].r;
        while(currL<L)
        {
            remove(currL);
            currL++;
        }
        while(currL>L)
        {
            add(currL-1);
            currL--;
        }
        while(currR>R+1)
        {
            remove(currR-1);
            currR--;
        }
        while(currR<=R) {
            add(currR);
            currR++;
        }

        ans[queries[i].ind]=brojac;
        if (!vv[0] && brojac*2 == (R - L + 1))
            res[queries[i].ind] = '1';
    }
    /*
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
     */
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    read();
    solve();
    return 0;
}