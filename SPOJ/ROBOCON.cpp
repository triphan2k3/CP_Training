#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "ROBOCON.INP"
#define out "ROBOCON.OUT"
using namespace std;
const int N=507;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N];
int f1[N][N],f2[N][N];
int n,k;
int x[2][3]={{1,0,1},{0,1,1}};
int y[2][3]={{0,1,1},{-1,0,-1}};
deque<ii> qleft,qrigh;

bool notin(int i,int j)
{
    return i==0 || j==0 || i==n+1 || j==n+1;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>k;
    for (int i=1,u,v;i<=k;i++)
    {
        cin>>u>>v;
        a[u][v]=1;
    }
    f1[1][1]=f2[1][n]=1;
    qleft.pb(mp(0,0));
    qleft.pb(mp(1,1));

    qrigh.pb(mp(0,0));
    qrigh.pb(mp(1,n));
    int num=0;
    while (1)
    {
        num++;
        while (qleft.size())
        {
            ii t=qleft.back();
            int i=t.X;
            int j=t.Y;
            qleft.pop_back();
            if (i==0) break;
            for (int k=0;k<3;k++)
            {
                int u=i+x[0][k];
                int v=j+y[0][k];
                if (notin(u,v)) continue;
                if (f1[u][v]==num+1) continue;
                if (a[u][v]) continue;
                f1[u][v]=num+1;
                qleft.push_front(mp(u,v));
            }
        }
        while (qrigh.size())
        {
            ii t=qrigh.back();
            int i=t.X;
            int j=t.Y;
            qrigh.pop_back();
            if (i==0) break;
            for (int k=0;k<3;k++)
            {
                int u=i+x[1][k];
                int v=j+y[1][k];
                if (notin(u,v)) continue;
                if (f2[u][v]==num+1) continue;
                if (a[u][v]) continue;
                f2[u][v]=num+1;
                if (f1[u][v]==num+1)
                {
                    cout<<num;
                    return 0;
                }
                qrigh.push_front(mp(u,v));
            }
        }
        qleft.push_front(mp(0,0));
        qrigh.push_front(mp(0,0));
    }
}
