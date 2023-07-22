#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QTREE3.INP"
#define out "QTREE3.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int par[N],valIT[N],posIT[N],chain[N],rchain[N],IT[10*N],sz[N];
int n,numIT,nchain;
void dfs(int u,int p)
{
    sz[u]=1;
    par[u]=p;
    for (int v:a[u])
        if (v!=p)
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
}

void hld(int u)
{
    if (rchain[nchain]==0)
        rchain[nchain]=u;
    chain[u]=nchain;
    posIT[u]=++numIT;
    valIT[numIT]=u;
    int _sz=0;
    int nxt=0;
    for (int v:a[u])
        if (chain[v]==0 && sz[v]>_sz)
        {
            _sz=sz[v];
            nxt=v;
        }
    if (nxt!=0)
    hld(nxt);
    for (int v:a[u])
        if (chain[v]==0)
        {
            nchain++;
            hld(v);
        }
}
int get(int id,int x,int y,int l,int r)
{
    if (l>y || r<x) return MOD;
    if (l>=x && r<=y) return IT[id];
    int m=(l+r)>>1;
    int xx=get(id*2,x,y,l,m);
    int yy=get(id*2+1,x,y,m+1,r);
    return min(xx,yy);
}
void update(int id,int x,int l,int r)
{
    if (r<x || l>x) return;
    if (l==r)
    {
        IT[id]=IT[id]==MOD ? x:MOD;
        return;
    }
    int m=(l+r)>>1;
    update(id*2,x,l,m);
    update(id*2+1,x,m+1,r);
    IT[id]=min(IT[id*2],IT[id*2+1]);
}
void query(int v)
{
    int ans=MOD;
    while (v)
    {
        int r=rchain[chain[v]];
        ans=min(ans,get(1,posIT[r],posIT[v],1,n));
        v=par[r];
    }
    if (ans<MOD)
        cout<<valIT[ans]<<"\n";
    else
    cout<<"-1\n";
}
int main()
{

    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    int u,v;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,0);
    nchain=1;
    hld(1);
    for (int i=1;i<=4*n;i++)
        IT[i]=MOD;
    while (q--)
    {
        cin>>u>>v;
        if (u==0) update(1,posIT[v],1,n);
        else query(v);
    }
}
