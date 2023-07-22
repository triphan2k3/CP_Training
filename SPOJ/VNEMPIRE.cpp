#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VNEMPIRE.INP"
#define out "VNEMPIRE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
ii x[N],y[N],z[N];
int ck[N],d[N],ans,n,m;
void edge(ii x,ii y)
{
    int u=x.Y;
    int v=y.Y;
    int w=abs(x.X-y.X);
    a[u].push_back(mp(w,v));
    a[v].push_back(mp(w,u));
}
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
        ans+=w;
        ck[u]=1;
        for (ii temp:a[u])
        {
            int v=temp.Y;
            w=temp.X;
            if (ck[v]) continue;
            if (d[v]>w)
            {
                d[v]=w;
                q.push(mp(w,v));
            }
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    a.resize(n+1);
    for (int i=1;i<=n;i++)
        cin>>x[i].first>>y[i].first>>z[i].first;
    for (int i=1;i<=n;i++)
        x[i].Y=y[i].Y=z[i].Y=i;
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    sort(z+1,z+n+1);
    for (int i=1,u,v,w;i<n;i++)
    {
        edge(x[i],x[i+1]);
        edge(y[i],y[i+1]);
        edge(z[i],z[i+1]);
    }
    findmst();
    cout<<ans;
}
