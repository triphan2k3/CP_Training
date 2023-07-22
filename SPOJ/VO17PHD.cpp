#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,int>
#define iii pair<ii,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VO17PHD.INP"
#define out "VO17PHD.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

vector<ii> a[N];
ll dp[N],d[N],p[N];
int m,n;

void dijkstra()
{
    priority_queue<ii,vector<ii>,greater<ii> > q;
    q.push({0,1});
    dp[1]=p[1];
    for (int i=2;i<=n;i++)
        d[i]=INF;
    while (q.size())
    {
        int u=q.top().Y;
        ll du=q.top().X;
        q.pop();
        if (du!=d[u]) continue;
        for (int i=0;i<a[u].size();i++)
        {
            ll  w=a[u][i].X;
            int v=a[u][i].Y;

            if (d[u]+w==d[v])
                dp[v]=max(dp[v],dp[u]+p[v]);
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                dp[v]=dp[u]+p[v];
                q.push({d[v],v});
            }
        }
    }
    if (d[n]==INF)
    {
        cout<<"impossible";
        return;
    }
    cout<<d[n]<<" "<<dp[n];
    return;
}

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p[i];
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    dijkstra();
    return 0;
}
