#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MBEEWALK.INP"
#define out "MBEEWALK.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[16][33][33];
int n,t;
int x[6]={1,1,-1,-1,0, 0};
int y[6]={0,1, 0,-1,1,-1};
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    f[0][15][15]=1;

    for (int i=0;i<=14;i++)
        for (int xx=2;xx<=30;xx++)
            for (int yy=2;yy<=30;yy++)
                for (int j=0;j<6;j++)
                    f[i+1][xx+x[j]][yy+y[j]]+=f[i][xx][yy];

    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<f[n][15][15]<<"\n";
    }
}
