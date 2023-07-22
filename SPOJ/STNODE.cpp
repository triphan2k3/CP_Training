#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "STNODE.INP"
#define out "STNODE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,m,s,t;
vector<vector<int>> e;
vector<int> path;
int dp[N];
int par[N];
int f[N];
int stt[N];

void dfs(int u)
{
    dp[u]=1;
    for (int v:e[u])
    {
        if (dp[v]) continue;
        par[v]=u;
        dfs(v);
    }
}

void dfss(int u)
{
    dp[u]=2;
    for (int v:e[u])
    {
        if (dp[v]==2)
        {
            if (stt[u]) f[v]=min(stt[u],f[v]);
            else f[v]=min(f[u],f[v]);
            continue;
        }
       if (!f[v]) f[v]=(stt[u]) ? stt[u]:f[u];
       if (!stt[v]) dfss(v);
    }

}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>s>>t;
    e.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        e[u].pb(v);
        //a[v].pb(u);
    }
    dfs(s);
    int u=t;
    path.pb(t);
    while (u!=s)
    {
        u=par[u];
        path.pb(u);
    }
    reverse(path.begin(),path.end());
    u=0;
    for (int v:path)
        stt[v]=++u;

    f[s]=1;
    for (int i:path)
        dfss(i);

    int res=0;
    reverse(path.begin(),path.end());
    u=f[t];
    for (int i=1;i<path.size()-1;i++)
    {
        if (stt[path[i]]<=u) res++;
        u=min(u,f[path[i]]);
    }
    cout<<res;
}
