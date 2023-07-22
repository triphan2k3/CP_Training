#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKCITY.INP"
#define out "NKCITY.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
int d[N],ok[N],m,n;
int findmst()
{
    int ans=-MOD;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,1));
    d[1]=0;
    for (int i=2;i<=n;i++)
        d[i]=MOD;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        int u=t.Y;
        if (d[u]!=t.X) continue;
        ans=max(ans,t.X);
        ok[u]=1;
        for (ii e:a[u])
        {
            int w=e.X;
            int v=e.Y;
            if (ok[v]) continue;
            if (d[v]>w)
            {
                q.push(mp(w,v));
                d[v]=w;
            }
        }
    }
    return ans;
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
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    cout<<findmst();

}
