#include <bits/stdc++.h>
#define ll long long
#define ii pair<long double,int>
#define data pair<int,int>
#define iii pair<ii,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NETACCEL.INP"
#define out "NETACCEL.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
long double d[N][15];
int check[N][15];
int m,n,k;

struct cmp
{
    bool operator () (iii a,iii b) {return a.X.X>b.X.X; }
};
void dijkstra()
{
    priority_queue<iii,vector<iii>,cmp> q;
    q.push({{0,1},0});
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++)
            d[i][j]=(long double)MOD;

    d[1][0]=0;
    while (q.size())
    {
        ii t=q.top().X;
        int tempk=q.top().Y;
        q.pop();
        int u=t.Y;
        if (t.X>d[u][tempk]) continue;

        for (ii e:a[u])
        {
            long double w=e.X;
            int v=e.Y;
            if (d[u][tempk]+w<d[v][tempk])
            {
                d[v][tempk]=d[u][tempk]+w;
                q.push({{d[v][tempk],v},tempk});
            }
            if (tempk<k)
                for (int tk=tempk+1;tk<=k;tk++)
                {
                    w=w/2.0;
                    if (d[u][tempk]+w<d[v][tk])
                    {
                        d[v][tk]=d[u][tempk]+w;
                        q.push({{d[v][tk],v},tk});
                    }
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
    for (int i=1,u,v;i<=m;i++)
    {
        long double w;
        cin>>u>>v>>w;
        a[u].pb(mp(w,v));
        a[v].pb(mp(w,u));
    }
    dijkstra();
    cout<<setprecision(2)<<fixed<<d[n][k];
}
