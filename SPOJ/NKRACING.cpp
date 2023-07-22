#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKRACING.INP"
#define out "NKRACING.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
int d[N],ck[N];
int m,n,ans;
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
        ans+=w;
    }
    priority_queue<ii,vector<ii>,less<ii>> q;
    q.push(mp(0,1));
    for (int i=2;i<=n;i++)
        d[i]=-MOD;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        int w=t.first;
        int u=t.second;
        if (d[u]!=w) continue;
        ck[u]=1;
        ans-=w;
        for (ii temp:a[u])
        {
            int v=temp.second;
            w=temp.first;
            if (w<=d[v] || ck[v]) continue;
            d[v]=w;
            q.push(mp(w,v));
        }
    }
    cout<<ans;
}
