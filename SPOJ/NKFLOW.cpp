#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKFLOW.INP"
#define out "NKFLOW.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int c[N][N];
int avail[N],trace[N];
int flow,m,n,s,t;

bool bfs()
{
    for (int i=1;i<=n;i++)
        avail[i]=0;
    deque<int> q;
    q.push_back(s);
    while (q.size())
    {
        int u=q.back();
        q.pop_back();
        for (int v:a[u])
            if (c[u][v]>0 && avail[v]==0)
            {
                avail[v]=1;
                q.push_front(v);
                trace[v]=u;
                if (v==t) return true;
            }
    }
    return false;
}
void upflow()
{
    int v=t;
    int up=MOD;
    while (v!=s)
        {
            int u=trace[v];
            up=min(up,c[u][v]);
            v=u;
        }
    v=t;
    while (v!=s)
    {
        int u=trace[v];
        c[u][v]-=up;
        c[v][u]+=up;
        v=u;
    }
    flow+=up;
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        c[u][v]=w;
        a[u].pb(v);
        a[v].pb(u);
    }
    while (bfs()) upflow();
    cout<<flow;
}
