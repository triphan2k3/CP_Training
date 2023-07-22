#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CRITICAL.INP"
#define out "CRITICAL.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
int f[N],num[N],low[N],gcc[N],soluong[N];
int m,n,t,numgcc;
ll res;
void dfs(int u,int p)
{
    num[u]=low[u]=++t;
    int used=1;
    f[u]=1;
    for (int v:a[u])
    {
        if (v==p) continue;
        if (num[v])
        {
            low[u]=min(num[v],low[u]);
            continue;
        }
        dfs(v,u);
        low[u]=min(low[u],low[v]);
        f[u]+=f[v];
        if (low[v]>=num[u])
        {
            used+=f[v];
            res+=f[v]*(soluong[gcc[v]]-used);
        }
    }
}
void dfsgcc(int u)
{
    gcc[u]=numgcc;
    soluong[numgcc]++;
    for (int v:a[u])
        if (!gcc[v]) dfsgcc(v);
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
        if (!gcc[i])
        {
            numgcc++;
            dfsgcc(i);
        }
    for (int i=1;i<=n;i++)
        if (!num[i])
            dfs(i,0);
    double ans=(double)res/(double)n;
    cout << setprecision(2) << fixed << ans;
    //printf("%.2lf",1.0*res/n);
}
