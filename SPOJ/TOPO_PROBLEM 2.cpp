#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
int last[N],topo[N],f[N];
int n,m,s,t,T;
void dfs(int u)
{
    if (last[u]) return;
    for (int v:a[u])
        dfs(v);
    last[u]=++T;
    topo[T]=u;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>s>>t;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[v].pb(u);
    }
    dfs(t);
    f[s]=1;
    for (int i=last[s]+1;i<=last[t];i++)
    {
        int u=topo[i];
        for (int v:a[u])
            f[u]+=f[v];
    }
    cout<<f[t];
}
