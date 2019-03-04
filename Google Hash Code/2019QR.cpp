#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;



int main()
{
    ifstream fin("C:\\Users\\iletavchioski\\Desktop\\in.txt");
    ofstream fout("C:\\Users\\iletavchioski\\Desktop\\out.txt");
    //freopen("out.txt", "w", stdout);
    vector<pair<double,pair<vector<string>,pair<int,int> > > > vh;
    vector<pair<int,pair<vector<string>,pair<int,int> > > > vv;
    int n;
    fin >> n;
    for (int i = 0; i<n; i++) {
        char a;
        fin>>a;
        if (a == 'H') {
            int k;
            fin >> k;
            vector<string> b;
            for (int j = 0; j < k ; j++) {
                string c;
                fin >> c;
                b.push_back(c);
            }
            vh.push_back(make_pair((double)b.size(),make_pair(b,make_pair(-1,i))));
        } else {
            int k;
            fin >> k;
            vector<string> b;
            for (int j = 0; j < k ; j++) {
                string c;
                fin >> c;
                b.push_back(c);
            }
            vv.push_back(make_pair((int)b.size(),make_pair(b,make_pair(-1,i))));
        }

    }

    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    int hor= vh.size();
    int ver = vv.size();
    if (ver%2==1)
        ver--;
    fout<<hor+(ver/2)<<endl;

    int b = vv.size();
    if (b%2)
        b--;
    for (int i = 1; i < b;i+=2) {
        map<string,int> m;
        int pres,raz,unija;
        vector<string> ace;
        int i1 = vv[i-1].second.second.second;
        int j1 = vv[i].second.second.second;
        for (int j = 0; j < vv[i].second.first.size();j++) {
            ace.push_back(vv[i].second.first[j]);
        }
        for (int j = 0; j < vv[i-1].second.first.size();j++) {
            ace.push_back(vv[i-1].second.first[j]);
        }
        for (int j = 0; j < ace.size(); j++) {
            m[ace[j]]++;
        }
        unija = m.size();
        for (int j = 0; j < ace.size();j++) {
            if (m[ace[j]] == 2)
                pres++;
        }
        vh.push_back(make_pair(unija/2-(pres),make_pair(ace,make_pair(i1,j1))));
    }
    sort(vh.begin(),vh.end());
    reverse(vh.begin(),vh.end());
    for (int i = 0 ; i < vh.size(); i++) {
        if (vh[i].second.second.first == -1)
            fout<<vh[i].second.second.second<<endl;
        else
            fout<<vh[i].second.second.first <<" "<<vh[i].second.second.second<<endl;
    }


    return 0;
}
