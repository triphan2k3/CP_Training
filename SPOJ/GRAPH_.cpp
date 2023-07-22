#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "GRAPH_.INP"
#define out "GRAPH_.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
int num[N],low[N],child[N],par[N],k[N];
int temp,cau,khop,m,n;

void dfs(int u,int p)
{
    if (num[u]) return;
    num[u]=low[u]=++temp;
    for (int v:a[u])
    {
        if (v==p) continue;
        if (num[v])
        {
            low[u]=min(low[u],num[v]);
            continue;
        }
        par[v]=u;
        dfs(v,u);
        low[u]=min(low[u],low[v]);
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for (int i=1;i<=n;i++)
        if (!num[i]) dfs(i,0);

    for (int i=1;i<=n;i++)
        child[par[i]]++;
    for (int i=1;i<=n;i++)
        if (par[i]==0 && child[i]>=2) k[i]=1;;
    for (int i=1;i<=n;i++)
        {

            int v=par[i];
            if (v==0) continue;
            if (low[i]==num[i]) cau++;
            if (low[i]>=num[v] && par[v]!=0) k[v]=1;
        }
    for (int i=1;i<=n;i++)
        if (k[i]) khop++;
    cout<<khop<<" "<<cau;
}
