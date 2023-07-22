#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CENTRE28.INP"
#define out "CENTRE28.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
int d[N],d1[N],num[N],low[N],par[N],khop[N];
int m,n,T;
void dfs(int u,int p)
{
    num[u]=low[u]=++T;
    for (ii e:a[u])
    {
        if (e.Y==p) continue;
        int v=e.Y;
        int w=e.X;
        if (d1[u]+w+d[v]!=d1[n] && d1[v]+w+d[u]!=d1[n]) continue;
        if (num[v])
            low[u]=min(low[u],num[v]);
        else
        {
            par[v]=u;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
    }
}
void dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,s));
    for (int i=1;i<=n;i++)
        d[i]=MOD;
    d[s]=0;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        if (t.X!=d[t.Y]) continue;
        int u=t.Y;
        for (ii e:a[u])
        {
            int v=e.Y;
            int w=e.X;
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                q.push(mp(d[v],v));
            }
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u].push_back(mp(w,v));
        a[v].push_back(mp(w,u));
    }
    dijkstra(1);
    for (int i=1;i<=n;i++)
        d1[i]=d[i];
    dijkstra(n);
    dfs(1,0);
    int ans=n-2;
    for (int v=2;v<=n;v++)
    {
        int u=par[v];
        if (u==1) continue;
        if (low[v]>=num[u])
        {
            if (khop[u]==1) continue;
            khop[u]=1;
            if (u!=n && u!=1 && u!=0)
                ans--;
        }
    }
    cout<<ans;
    for (int i=2;i<n;i++)
        if (!khop[i]) cout<<"\n"<<i;
}
