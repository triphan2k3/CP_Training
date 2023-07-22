#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "FSELECT.INP"
#define out "FSELECT.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
const int K=19;

vector<vector<int>> a,am;
int ptab[N][K];
int h[N],par[N];
int n,m,root;
void dfs(int u)
{
    for (int i=0;i<a[u].size();i++)
    {
    	int v=a[u][i];
        h[v]=h[u]+1;
        dfs(v);
    }
}
void lcasetup()
{
    for (int i=1;i<=n;i++)
        ptab[i][0]=par[i];

    for (int k=1;k<K;k++)
        for (int i=1;i<=n;i++)
        ptab[i][k]=ptab[ptab[i][k-1]][k-1];
}
int lca(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    for (int i=K-1;i>=0;i--)
        if (h[u]-(1<<i)>=h[v])
            u=ptab[u][i];

    for (int i=K-1;i>=0;i--)
        if (ptab[u][i]!=ptab[v][i])
            u=ptab[u][i],
            v=ptab[v][i];
    if (u==v) return u;
    return par[u];
}
void proces(int st)
{
    int maxhigh=am[st][0];
    for (int i=1;i<am[st].size();i++)
        maxhigh=(h[am[st][i]]>h[maxhigh]) ? am[st][i]:maxhigh;

    int res=0;
    for (int i=0;i<am[st].size();i++)
    {
        int u=am[st][i];
        int t=lca(u,maxhigh);
        res=max(res,h[maxhigh]-h[t]+h[u]-h[t]);
    }
    cout<<res<<"\n";
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    a.resize(n+1);
    am.resize(m+1);
    for (int i=1,u,v;i<=n;i++)
    {
        cin>>u>>v;
        am[u].pb(i);
        par[i]=v;
        if (v) a[v].pb(i);
        else root=i;
    }
    dfs(root);
    lcasetup();
    for (int i=1;i<=m;i++)
        proces(i);

}
