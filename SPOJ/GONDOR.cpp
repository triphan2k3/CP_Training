#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define id pair<double,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "GONDOR.INP"
#define out "GONDOR.OUT"
using namespace std;
const int N=(int)1e2+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
double d[N];
int x[N],y[N],ok[N],sz[N],n;
int a[N][N];
double dis(int i,int j)
{
    double xx=x[i]-x[j];
    double yy=y[i]-y[j];
    return sqrt(xx*xx+yy*yy);
}
void dijkstra()
{
    priority_queue<id,vector<id>,greater<id>> q;
    q.push({0,1});
    for (int i=2;i<=n;i++)
        d[i]=MOD;
    while (q.size())
    {
        double du=q.top().X;
        int u=q.top().Y;
        q.pop();
        ok[u]=1;
        if (du>d[u]) continue;
        int cnt=0;
        for (int i=1;i<=n-1;i++)
        if (!ok[a[u][i]])
        {
            int v=a[u][i];
            if (du+dis(u,v)<d[v])
            {
                d[v]=d[u]+dis(u,v);
                q.push({d[v],v});
            }
            cnt++;
            if (cnt==sz[u]) break;
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>sz[i];
        for (int j=1;j<n;j++)
            cin>>a[i][j];
    }
    dijkstra();
    for (int i=1;i<=n;i++)
        cout<<setprecision(6)<<fixed<<d[i]<<"\n";
}
