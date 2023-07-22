#include <bits/stdc++.h>
#define ll long long
#define ii pair<double,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PWRFAIL.INP"
#define out "PWRFAIL.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int x[N],y[N];
int a[N][N];
int n,m;
double w;
double d[N];

double dis(int i,int j)
{
    double xx=x[i]-x[j];
    double yy=y[i]-y[j];
    return sqrt(xx*xx+yy*yy);
}

void dijkstra()
{
    priority_queue<ii,vector<ii>,greater<ii>>  q;
    q.push({0,1});
    for (int i=2;i<=n;i++)
        d[i]=MOD;
    while (q.size())
    {
        double du=q.top().X;
        int u=q.top().Y;
        q.pop();
        if (du>d[u]) continue;
        for (int v=1;v<=n;v++)
            if (a[u][v])
            {
                if (d[v]<=d[u]) continue;
                d[v]=d[u];
                q.push({d[v],v});
            } else if (dis(u,v)<=w)
            {
                if (d[u]+dis(u,v)<d[v])
                {
                    d[v]=d[u]+dis(u,v);
                    q.push({d[v],v});
                }
            }

    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>w;
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
        a[v][u]=1;
    }
    dijkstra();
    if (d[n]<MOD)
        cout<<(int)(d[n]*1000);
    else cout<<"-1";

}
