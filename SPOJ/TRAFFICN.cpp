#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "TRAFFICN.INP"
#define out "TRAFFICN.OUT"
using namespace std;
const int N=(int)1e4+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<iii> a[N];
int d[2][N];
int m,n,s,t;

void dijkstra(int s,int k)
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,s});
    for (int i=1;i<=n;i++)
        d[k][i]=MOD;
    d[k][s]=0;
    while (q.size())
    {
        int u=q.top().Y;
        int du=q.top().X;
        q.pop();
        if (du!=d[k][u]) continue;
        for (int i=0;i<a[u].size();i++)
        if (a[u][i].Y==k)
        {
            ii e=a[u][i].X;
            int v=e.X;
            int w=e.Y;
            if (du+w<d[k][v])
            {
                d[k][v]=du+w;
                q.push({d[k][v],v});
            }
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int q;
    cin>>q;
    while (q--)
    {
        int k;
        cin>>n>>m>>k>>s>>t;
        for (int i=1;i<=n;i++)
            a[i].clear();
        for (int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            a[u].pb({{v,w},0});
            a[v].pb({{u,w},1});
        }
        dijkstra(s,0);
        dijkstra(t,1);
        int res=d[0][t];

        for (int i=1;i<=k;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            res=min(d[0][u]+d[1][v]+w,res);
            res=min(d[0][v]+d[1][u]+w,res);
        }
        if (res==MOD)
            cout<<-1<<"\n";
        else
        cout<<res<<"\n";
    }
}
