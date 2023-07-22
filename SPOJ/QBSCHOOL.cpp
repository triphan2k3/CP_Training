#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBSCHOOL.INP"
#define out "QBSCHOOL.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
ll f[N];
int ck[N],d[N],n,m;
void dijkstra()
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,1));
    f[1]=1;
    for (int i=2;i<=n;i++)
        d[i]=MOD;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        if (t.X!=d[t.Y]) continue;
        int s=t.X;
        int u=t.Y;
        if (u==n) return;
        ck[u]=1;
        for (ii temp:a[u])
        {
            int v=temp.Y;
            int w=temp.X;
            if (s+w>d[v]) continue;
            if (s+w==d[v])
                f[v]+=f[u];
            else
            {
                f[v]=f[u];
                q.push(mp(s+w,v));
                d[v]=s+w;
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
    for (int i=1,l,u,v,w;i<=m;i++)
    {
        cin>>l>>u>>v>>w;
        a[u].push_back(mp(w,v));
        if (l==2)
        a[v].push_back(mp(w,u));
    }
    dijkstra();
    cout<<d[n]<<" "<<f[n];
}
