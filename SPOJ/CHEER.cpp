#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CHEER.INP"
#define out "CHEER.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
int f[N],d[N],ck[N];
int m,n;
int ans=MOD;
void findmst()
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,1));
    for (int i=2;i<=n;i++)
        d[i]=MOD;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        int w=t.X;
        int u=t.Y;
        if (d[u]!=w) continue;
        ck[u]=1;
        ans+=w;
        for (ii temp:a[u])
        {
            w=temp.X;
            int v=temp.Y;
            if (w>=d[v] || ck[v]) continue;
            d[v]=w;
            q.push(mp(w,v));
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>f[i];
        ans=min(ans,f[i]);
    }
    a.resize(n+1);
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        w=w+w+f[u]+f[v];
        a[u].pb(mp(w,v));
        a[v].pb(mp(w,u));
    }
    findmst();
    cout<<ans;
}
