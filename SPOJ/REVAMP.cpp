#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,int>
#define iii pair<ii,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "REVAMP.INP"
#define out "REVAMP.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
ll d[N][22];
int m,n,k;
void dijkstra()
{
    priority_queue<iii,vector<iii>,greater<iii>> q;
    q.push({{0,1},0});
    for (int i=2;i<=n;i++)
        for (int j=0;j<=k;j++)
            d[i][j]=INF;
    while (q.size())
    {
        ll du=q.top().X.X;
        int u=q.top().X.Y;
        int tempk=q.top().Y;
        q.pop();
        if (du!=d[u][tempk]) continue;
        for (ii e:a[u])
        {
            int v=e.Y;
            ll w=e.X;
            if (d[u][tempk]+w<d[v][tempk])
            {
                d[v][tempk]=d[u][tempk]+w;
                q.push({{d[v][tempk],v},tempk});
            }
            if (tempk<k && d[u][tempk]<d[v][tempk+1])
            {
                d[v][tempk+1]=d[u][tempk];
                q.push({{d[v][tempk+1],v},tempk+1});
            }
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>k;
    a.resize(n+1);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        a[u].pb(mp(w,v));
        a[v].pb(mp(w,u));
    }
    dijkstra();
    ll res=d[n][0];
    for (int i=1;i<=k;i++)
        res=min(d[n][i],res);
    cout<<res;
}
