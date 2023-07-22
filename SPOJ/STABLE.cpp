#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "STABLE.INP"
#define out "STABLE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int m,n,s;
vector<vector<int>> e;
ii a[N];
int f[N];
int h[N];

void bfs()
{
    deque<int> q;
    q.pb(s);
    h[s]=1;
    f[s]=1;
    while (q.size())
    {
        int u=q.back();
        if (f[u]>2) f[u]=2;
        q.pop_back();
        for (int v:e[u])
            if (!h[v])
            {
                h[v]=h[u]+1;
                f[v]=f[u];
                q.push_front(v);
            } else
                f[v]=(h[u]+1==h[v]) ? f[u]+f[v]:f[v];
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>s;
    e.resize(n+1);
    for (int i=1;i<=m;i++)
        cin>>a[i].X>>a[i].Y;
    sort(a+1,a+m+1);

    for (int i=1;i<=m;i++)
    if (a[i]!=a[i-1]) e[a[i].X].pb(a[i].Y);
    bfs();
    int res=0;
    for (int i=1;i<=n;i++)
        if (f[i]>=2) res++;
    cout<<res;
}
