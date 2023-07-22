#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBMST.INP"
#define out "QBMST.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
ii res[N];
int d[N],path[N],ok[N];
int m,n,ans;
/*
struct cmp
{
    bool operator () (ii a,ii b) {return a.X>b.X;}
};
*/
void findmst()
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(make_pair(0,1));
    for (int i=2;i<=n;i++)
        d[i]=MOD;

    while (q.size())
    {
        ii temp=q.top();
        q.pop();
        int w=temp.X;
        int u=temp.Y;
        if (w!=d[u]) continue;
        //res[u]=mp(w,path[u]);
        ans+=w;
        ok[u]=1;
        for (ii t:a[u])
        {
            int v=t.Y;
            if (ok[v]) continue;
            w=t.X;
            if (w<d[v])
            {
                d[v]=w;
                q.push(mp(w,v));
                path[v]=u;
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
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u].push_back(mp(w,v));
        a[v].push_back(mp(w,u));
    }
    findmst();
    /*
    for (int i=2;i<=n;i++)
        ans+=res[i].X;
        cout<<i<<' '<<res[i].Y<<"\n";
    */
    cout<<ans;
}
