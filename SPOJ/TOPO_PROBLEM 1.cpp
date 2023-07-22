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
int ck[N],last[N],topo[N],f[N];
int n,m,T;
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
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[v].pb(u);
        ck[u]=1;
    }
    for (int i=1;i<=n;i++)
        if (!ck[i]) a[0].pb(i);

    dfs(0);

    cout<<"AFTER TOPO SORT:\n";
    for (int i=1;i<=n;i++)
        cout<<topo[i]<<" ";
    for (int i=1;i<=n;i++)
    {
        int u=topo[i];
        for (int v:a[u])
            f[u]=max(f[u],f[v]+1);
    }
    cout<<"\nAFTER DP:\n";
    for (int i=1;i<=n;i++)
        cout<<f[i]<<" ";
}
