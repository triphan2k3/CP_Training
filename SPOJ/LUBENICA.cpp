#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "LUBENICA.INP"
#define out "LUBENICA.OUT"
using namespace std;
const int N=(int)1e5+7;
const int K=20;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int pmin[N][K],pmax[N][K],ptab[N][K];
int par[N],h[N],cost[N];
vector<vector<ii>> a;
int m,n;

void dfs(int u,int p)
{
    for (ii v:a[u])
    {
        if (v.X==p) continue;
        par[v.X]=u;
        cost[v.X]=v.Y;
        h[v.X]=h[u]+1;
        dfs(v.X,u);
    }
}
void setup()
{
    for (int i=1;i<=n;i++)
    {
        ptab[i][0]=par[i];
        pmin[i][0]=pmax[i][0]=cost[i];
    }
    for (int i=1;i<=17;i++)
        pmin[0][i]=MOD;

    for (int k=1;k<=17;k++)
        for (int i=1;i<=n;i++)
        {
            if (h[i] < 1<<k) continue;
            int t=ptab[i][k-1];
            ptab[i][k]=ptab[t][k-1];
            pmin[i][k]=min(pmin[i][k-1],pmin[t][k-1]);
            pmax[i][k]=max(pmax[i][k-1],pmax[t][k-1]);
        }
}
void query(int u,int v)
{
    if (u==v)
    {
        cout<<"0 0\n";
        return;
    }
    if (h[u]<h[v]) swap(u,v);
    int maxu=0,maxv=0,minu=MOD,minv=MOD;
    for (int i=17;i>=0;i--)
    {
        if (h[u]-(1<<i)<h[v]) continue;
        minu=min(minu,pmin[u][i]);
        maxu=max(maxu,pmax[u][i]);
        u=ptab[u][i];
    }
    for (int i=17;i>=0;i--)
    {
        if (ptab[u][i]==ptab[v][i]) continue;
        minu=min(minu,pmin[u][i]);
        maxu=max(maxu,pmax[u][i]);
        minv=min(minv,pmin[v][i]);
        maxv=max(maxv,pmax[v][i]);
        u=ptab[u][i];
        v=ptab[v][i];
    }
    if (u!=1 && u!=v)
    {
        minu=min(minu,cost[u]);
        maxu=max(maxu,cost[u]);
    }
    if (v!=1 && u!=v)
    {
        minv=min(minv,cost[v]);
        maxv=max(maxv,cost[v]);
    }
    cout<<min(minu,minv)<<" "<<max(maxu,maxv)<<"\n";
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    a.resize(n+1);
    int u,v,w;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
    dfs(1,-1);
    setup();
    cin>>n;
    while (n--)
    {
        cin>>u>>v;
        query(u,v);
    }
}
