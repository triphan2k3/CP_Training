#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "WEATHER.INP"
#define out "WEATHER.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
int num[N],low[N],f[N];
int m,n,res,t;
void dfs(int u,int p)
{
    num[u]=low[u]=++t;
    f[u]=1;
    for (int v:a[u])
    {
        if (v==p) continue;
        if (num[v])
        {
            low[u]=min(low[u],num[v]);
            continue;
        }
        dfs(v,u);
        f[u]+=f[v];
        low[u]=min(low[u],low[v]);
        if (low[v]==num[v]) res+=f[v]*(n-f[v]);
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
    dfs(1,0);
    cout<<res;
}
