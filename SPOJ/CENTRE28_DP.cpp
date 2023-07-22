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
int d[N],d1[N];
ll f[N],f1[N];
int m,n;
void dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,s));
    for (int i=1;i<=n;i++)
        d[i]=MOD;
    d[s]=0;
    f[s]=1;
    while (q.size())
    {
        ii t=q.top(); q.pop();
        int u=t.Y;
        if (d[u]!=t.X) continue;
        for (ii e:a[u])
        {
            int v=e.Y;
            int w=e.X;
            if (d[u]+w==d[v])
                f[v]+=f[u];
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                f[v]=f[u];
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
        a[u].pb(mp(w,v));
        a[v].pb(mp(w,u));
    }
    dijkstra(1);
    for (int i=1;i<=n;i++)
    {
        f1[i]=f[i];
        d1[i]=d[i];
    }
    dijkstra(n);
    int ans=0;
    for (int i=2;i<n;i++)
        if ((d1[i]+d[i]!=d1[n]) || (d1[i]+d[i]==d1[n] && f1[i]*f[i]<f1[n])) ans++;
    cout<<ans;
    for (int i=2;i<n;i++)
        if ((d1[i]+d[i]!=d1[n]) || (d1[i]+d[i]==d1[n] && f1[i]*f[i]<f1[n]))
            cout<<"\n"<<i;

}
