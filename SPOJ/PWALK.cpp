#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PWALK.INP"
#define out "PWALK.OUT"
using namespace std;
const int N=(int)1e3+7;
const int K=11;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
int par[N],h[N],cost[N];
int ptab[N][K];
int n;
void buildtree(int u,int p)
{
    for (ii x:a[u])
    {
        if ((x.X)==p) continue;
        cost[x.X]=x.Y+cost[u];
        par[x.X]=u;
        h[x.X]=h[u]+1;
        buildtree(x.X,u);
    }
}

void setup()
{
    for (int i=1;i<=n;i++)
        ptab[i][0]=par[i];
    for (int k=1;k<=10;k++)
        for (int i=1;i<=n;i++)
        {
            if (h[i] < 1<<k) continue;
            ptab[i][k]=ptab[ptab[i][k-1]][k-1];
        }
}

int lca(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    for (int i=10;i>=0;i--)
    {
        if (h[u]-(1<<i) < h[v]) continue;
        u=ptab[u][i];
    }

    for (int i=10;i>=0;i--)
    {
        if (ptab[u][i]==ptab[v][i]) continue;
        u=ptab[u][i];
        v=ptab[v][i];
    }
    if (u==v) return u;
    else return par[u];
}
void query(int u,int v)
{
    int t=lca(u,v);
    cout<<cost[u]-cost[t]+cost[v]-cost[t]<<"\n";
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int q;
    cin>>n>>q;
    a.resize(n+1);
    int u,v,w;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
    buildtree(1,0);
    setup();
    while (q--)
    {
        cin>>u>>v;
        query(u,v);
    }
}
