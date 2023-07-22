#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "COLLECT.INP"
#define out "COLLECT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct data
{
    int st,nd,rd;
};
int f[5][5][5];
int sw[1001][7];
int res;
deque<data> q;
data make(int a,int b,int c)
{
    data t;
    t.st=a;
    t.nd=b;
    t.rd=c;
    return t;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int k,solan,z,s,m,z0,m0,s0;
    cin>>solan>>z>>s>>m>>z0>>s0>>m0;
    f[z][s][m]=1;
    k=1;
    while (scanf("%d",&sw[k][1])==1)
    {
        for (int j=2;j<=6;j++)
            cin>>sw[k][j];
        k++;
    }
    k--;
    q.push_back(make(z,s,m));
    while (q.size())
    {
        data t=q.back();
        q.pop_back();
        int x=t.st;
        int y=t.nd;
        int z=t.rd;
        if (x>=z0 && y>=s0 && z>=m0) continue;
        for (int i=1;i<=k;i++)
        {
            int v1=x+sw[i][4]-sw[i][1];
            int v2=y+sw[i][5]-sw[i][2];
            int v3=z+sw[i][6]-sw[i][3];

            if (x<sw[i][1] || y<sw[i][2] || z<sw[i][3]) continue;
            if (v1 > 4 || v2 > 4 || v3 > 4) continue;
            if (f[v1][v2][v3]) continue;
            f[v1][v2][v3]=f[x][y][z]+1;
            q.push_front(make(v1,v2,v3));
        }
    }
    solan++;
    for (int i=z0;i<=4;i++)
        for (int j=s0;j<=4;j++)
            for (int jj=m0;jj<=4;jj++)
                if (f[i][j][jj] && f[i][j][jj]<=solan) res++;
    if (res==0)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<res<<"\n";
    for (int i=z0;i<=4;i++)
        for (int j=s0;j<=4;j++)
            for (int jj=m0;jj<=4;jj++)
                if (f[i][j][jj] && f[i][j][jj]<=solan) cout<<i<<" "<<j<<" "<<jj<<" "<<f[i][j][jj]-1<<"\n";
}
