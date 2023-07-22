#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MINCOST.INP"
#define out "MINCOST.OUT"
using namespace std;
const int N=(int)1e2+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int m,n,s,t,k,flow,mincost;
int w[N][N],c[N][N],f[N][N];
int trace[N],d[N],inq[N];

bool bellmanford()
{
    for (int i=1;i<=n;i++)
        d[i]=MOD;
    d[s]=0;
    deque<int> q;
    q.push_back(s);
    while (q.size())
    {
        int u=q.back(); q.pop_back();
        inq[u]=0;
        for (int v=1;v<=n;v++)
        {
            int W=f[u][v]<0 ? -w[u][v]:w[u][v];
            if (f[u][v]<c[u][v])
            if (d[v]>d[u]+W)
            {
                d[v]=d[u]+W;
                trace[v]=u;
                if (!inq[v])
                    q.push_back(v);
                inq[v]=1;
            }
        }
    }
    return d[n]!=MOD;
}
void upflow()
{
    int v=n;
    int delta=MOD;
    while (v!=s)
    {
        int u=trace[v];
        delta=min(delta,f[u][v]<0 ? -f[u][v]:c[u][v]-f[u][v]);
        v=u;
    }
    v=n;
    while (v!=s)
    {
        int u=trace[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
        v=u;
    }
    flow+=delta;
    mincost+=d[n]*delta;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>k>>s>>t;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        cin>>w[u][v]>>c[u][v];
        w[v][u]=w[u][v];
        c[v][u]=c[u][v];
    }
    n++;
    c[t][n]=c[n][t]=k;
    while (bellmanford())
        upflow();
    if (flow<k)
    {
        cout<<-1;
        return 0;
    }
    cout<<mincost<<"\n";
    for (int i=1;i<n;i++)
        for (int j=1;j<n;j++)
        if (f[i][j]>0)
        cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
    cout<<"0 0 0";

}
