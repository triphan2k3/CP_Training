#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BIC.INP"
#define out "BIC.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
int last[N],fir[N],topo[N],f[N],inpath[N];
int n,m,T,G;

void dfs(int u)
{
    fir[u]=++G;
    if (u==1)
    {
        f[u]=1;
        inpath[u]=1;
        last[u]=++T;
        for (int v:a[u])
            if (fir[v]>0 && last[v]==0) f[u]=-1;
        return;
    }
    for (int v:a[u])
    {
        if (fir[v])
        {
            if (!last[v]) f[u]=-1;
            else if (inpath[v])
            {
                if (f[v]==-1) f[u]=-1;
                else
                if (f[u]!=-1) f[u]+=f[v];
            }
            continue;
        }
        dfs(v);
        if (!inpath[v]) continue;
        if (f[v]==-1) f[u]=-1;
        else if (f[u]!=-1) f[u]+=f[v];
        inpath[u]=1;
    }
    last[u]=++T;

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
        a[v].push_back(u);
    }
    dfs(2);
    if (f[2]==-1) cout<<"inf";
    else cout<<f[2];
}
