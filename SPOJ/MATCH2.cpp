#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MATCH2.INP"
#define out "MATCH2.OUT"
using namespace std;
const int N=(int)1e3+7;
const int INF=(int)1e9+7;
const ll INFF=(ll)1e18+7;
int t,n;
int q[N],matchx[N],matchy[N],trace[N],visitx[N],visity[N],fx[N],fy[N];
int c[N][N];
vector<ii> ans;
int bfs(int s)
{
    int l=0;
    int r=0;
    for (int i=1;i<=n;i++)
        visitx[i]=visity[i]=trace[i]=0;
    q[r]=s;
    while (l<=r)
    {
        int x=q[l++];
        visitx[x]=1;
        for (int y=1;y<=n;y++)
            if (!visity[y] && c[x][y]-fx[x]-fy[y]==0)
            {
                visity[y]=1;
                trace[y]=x;
                if (matchy[y]) q[++r]=matchy[y];
                else return t=y;
            }
    }
    return 0;
}
void subxaddy()
{
    int delta=INF;
    for (int x=1;x<=n;x++)
        for (int y=1;y<=n;y++)
            if (visitx[x] && !visity[y]) delta=min(delta,c[x][y]-fx[x]-fy[y]);

    for (int x=1;x<=n;x++)
        if (visitx[x]) fx[x]+=delta;
    for (int y=1;y<=n;y++)
        if (visity[y]) fy[y]-=delta;
}
void upmatch()
{
    while (t)
    {
        int x=trace[t];
        int y=t;
        t=matchx[x];
        matchx[x]=y;
        matchy[y]=x;
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            c[i][j]=INF;
    int a,b,w;
    while (scanf("%d%d%d",&a,&b,&w)==3)
        c[a][b]=w;

    for (int i=1;i<=n;i++)
        fx[i]=fy[i]=INF;
    for (int x=1;x<=n;x++)
        for (int y=1;y<=n;y++)
            fx[x]=min(fx[x],c[x][y]);

    for (int y=1;y<=n;y++)
        for (int x=1;x<=n;x++)
            fy[y]=min(fy[y],c[x][y]-fx[x]);

    for (int i=1;i<=n;i++)
    {
        while (!bfs(i)) subxaddy();
        upmatch();
    }
    int res=0;
    for (int i=1;i<=n;i++)
        if (matchx[i] && c[i][matchx[i]]<INF)
        {
            res+=c[i][matchx[i]];
            ans.pb({i,matchx[i]});
        }
    cout<<res<<"\n";
    for (int i=0;i<ans.size();i++)
        cout<<ans[i].X<<" "<<ans[i].Y<<"\n";
}
