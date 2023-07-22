#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QTREE2.INP"
#define out "QTREE2.OUT"
using namespace std;
const int N=(int)1e4+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a[N];
int nchild[N],h[N],par[N],valIT[N],chain[N],posIT[N],rchain[N],IT[4*N],nodeatIT[N];
int n,numIT,nchain;
void dfs(int u,int p)
{
    nchild[u]=1;
    par[u]=p;
    h[u]=h[p]+1;
    for (ii e:a[u])
        if (e.X!=p)
        {
            dfs(e.X,u);
            nchild[u]+=nchild[e.X];
        }
}
void hld(int u,int w)
{
    if (rchain[nchain]==0)
        rchain[nchain]=u;
    chain[u]=nchain;
    posIT[u]=++numIT;
    nodeatIT[numIT]=u;
    valIT[numIT]=w;
    int sz=0;
    int nxt=0;
    for (ii e:a[u])
        if (nchild[e.X]>sz && chain[e.X]==0)
        {
            sz=nchild[e.X];
            nxt=e.X;
            w=e.Y;
        }
    if (nxt!=0)
        hld(nxt,w);

    for (ii e:a[u])
        if (chain[e.X]==0)
    {
        nchain++;
        hld(e.X,e.Y);
    }
}
void build(int id,int l,int r)
{
    if (l==r)
    {
        IT[id]=valIT[l];
        return;
    }
    int m=(l+r)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    IT[id]=IT[id*2]+IT[id*2+1];
}

int get(int id,int x,int y,int l,int r)
{
    if (r<x || l>y) return 0;
    if (l>=x && r<=y) return IT[id];
    int m=(l+r)>>1;
    int xx=get(id*2,x,y,l,m);
    int yy=get(id*2+1,x,y,m+1,r);
    return xx+yy;
}
void ansof(int u,int v,int _lca)
{
    int ans=0;
    while (chain[u]!=chain[_lca])
    {
        int r=rchain[chain[u]];
        ans+=get(1,posIT[r],posIT[u],1,n);
        u=par[r];
    }

    if (u!=_lca)
        ans+=get(1,posIT[_lca]+1,posIT[u],1,n);
        //cout<<ans<<" ";
    u=v;
    while (chain[u]!=chain[_lca])
    {
        int r=rchain[chain[u]];
        ans+=get(1,posIT[r],posIT[u],1,n);
        u=par[r];
    }
    if (u!=_lca)
        ans+=get(1,posIT[_lca]+1,posIT[u],1,n);
    cout<<ans<<"\n";
}
void node(int k,int u)
{
    int hu=h[u];
    while (1)
    {
        int r=rchain[chain[u]];
        if (h[u]-h[r]+1 >= k)
        {
            cout<<nodeatIT[posIT[u]-k+1]<<"\n";
            return;
        }
        k-=h[u]-h[r]+1;
        u=par[r];
    }
}
void resetvar()
{
    nchain=1;
    numIT=0;
    for (int i=1;i<=n;i++)
        rchain[i]=chain[i]=0;
    for (int i=1;i<=n;i++)
        a[i].clear();
}
int lca(int u,int v)
{
    while (chain[u]!=chain[v])
    {

        if (h[par[rchain[chain[u]]]]>h[par[rchain[chain[v]]]]) u=par[rchain[chain[u]]];
        else v=par[rchain[chain[v]]];
    }
    return h[u]>h[v] ? v:u;
}
void dist()
{
    int u,v;
    cin>>u>>v;
    int t=lca(u,v);
    ansof(u,v,t);
}
void knode()
{
    int u,v,k;
    cin>>u>>v>>k;
    int t=lca(u,v);
    int xx=h[u]-h[t]+1;
    int yy=h[v]-h[t];
    if (xx>=k)
        node(k,u);
    else node(yy-k+xx+1,v);
}
void QQ()
{
    string s;
    int a,b;
    while (1)
    {
        cin>>s;
        if (s[1]=='O') return;
        if (s[1]=='I') dist();
        else knode();
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        resetvar();
        for (int i=1;i<n;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            a[u].pb(mp(v,w));
            a[v].pb(mp(u,w));
        }
        dfs(1,0);
        hld(1,0);
        build(1,1,n);
        QQ();
    }
}
