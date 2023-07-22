#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QTREE.INP"
#define out "QTREE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a[N];
ii ed[N];
int sz[N],h[N],par[N],chain[N],rchain[N],posIT[N],edge[N],valIT[N],IT[N],w[N];
int ptab[100000][20];
int nchain,numIT,n;
void dfs(int u,int p)
{
    sz[u]=1;
    h[u]=h[p]+1;
    for (ii v:a[u])
    {
        int ez=v.X;
        if (ez!=p)
        {
            par[ez]=u;
            edge[ez]=v.Y;
            dfs(ez,u);
            sz[u]+=sz[ez];
        }
    }
}

void hldbuild(int u)
{
    if (chain[u]==0)
    {
        chain[u]=++nchain;
        rchain[nchain]=u;
    }
    posIT[u]=++numIT;
    valIT[numIT]=u;
    int next=0;
    int _sz=0;
    for (ii v:a[u])
    {
        int ez=v.X;
        if (ez!=par[u] && sz[ez]>_sz)
        {
            _sz=sz[ez];
            next=ez;
        }
    }
    if (next!=0)
    {
        chain[next]=nchain;
        hldbuild(next);
    }
    for (ii v:a[u])
        if (!chain[v.X] && par[u]!=v.X)
            hldbuild(v.X);
}

void update(int i,int x,int val,int l,int r)
{
    if (l>x || r<x) return;
    if (l==r)
    {
        IT[i]=val;
        return;
    }
    int m=(l+r)>>1;
    update(i<<1,x,val,l,m);
    update((i<<1)+1,x,val,m+1,r);
    if (IT[i<<1]>IT[(i<<1)+1])
        IT[i]=IT[i<<1];
    else IT[i]=IT[(i<<1)+1];
    //IT[i]=max(IT[i*2],IT[i*2+1]);
}

int get(int i,int x,int y,int l,int r)
{
    //if (x>y) return 0;
    if (l>y || r<x) return 0;
    if (l==r) return IT[i];
    if (l>=x && r<=y) return IT[i];
    int m=(l+r)>>1;
    int xx=get(i<<1,x,y,l,m);
    int yy=get((i<<1)+1,x,y,m+1,r);
    if (xx>yy) return xx;
    return yy;
}
void build(int i,int l,int r)
{
    if (l==r)
    {
        IT[i]=w[edge[valIT[l]]];
        return;
    }
    int m=(l+r)>>1;
    build(i<<1,l,m);
    build((i<<1)+1,m+1,r);
    IT[i]=max(IT[i<<1],IT[(i<<1)+1]);
}

int lca(int u,int v)
{

    if (h[u]<h[v])
    {
        int i=u;
        u=v;
        v=i;
    };
    for (int i=14;i>=0;i--)
        if (h[ptab[u][i]]>=h[v])
            u=ptab[u][i];

    for (int i=14;i>=0;i--)
        if (ptab[u][i]!=ptab[v][i])
        {
            u=ptab[u][i];
            v=ptab[v][i];
        }
    if (u==v) return u;
    return par[u];
}
void setup()
{
     for (int i=0;i<=14;i++)
        for (int u=1;u<=n;u++)
            ptab[u][i]=0;

    for (int i=1;i<=n;i++)
        ptab[i][0]=par[i];

    for (int i=1;i<=14;i++)
        for (int u=1;u<=n;u++)
            ptab[u][i]=ptab[ptab[u][i-1]][i-1];
}
void query1()
{
    int num,val;
    cin>>num>>val;
    int u=ed[num].X;
    int v=ed[num].Y;
    if (par[u]==v)
    {
        int i=u;
        u=v;
        v=i;
    }
    int head=rchain[chain[v]];
    update(1,posIT[v],val,1,n);
}
void query2()
{
    int u,v;
    cin>>u>>v;
    int t=lca(u,v);
    int ans=0;
    while (chain[u]!=chain[t])
    {
        int head=rchain[chain[u]];
        int tp=get(1,posIT[head],posIT[u],1,n);
        if (tp>ans) ans=tp;
        //ans=max(ans,get(1,posIT[head]+1,posIT[u],1,n));
        u=par[head];
    }
    if (u!=t)
    ans=max(ans,get(1,posIT[t]+1,posIT[u],1,n));
    u=v;
    while (chain[u]!=chain[t])
    {

        int head=rchain[chain[u]];
        //if (head!=u)
        int tp=get(1,posIT[head],posIT[u],1,n);
        if (tp>ans) ans=tp;
        //ans=max(ans,get(1,posIT[head]+1,posIT[u],1,n));
        u=par[head];
    }
    if (u!=t)
    ans=max(ans,get(1,posIT[t]+1,posIT[u],1,n));
    cout<<ans<<"\n";
    return;
}
void input()
{
    cin>>n;
    nchain=numIT=0;
    for (int i=1;i<=n;i++)
        a[i].clear();
    for (int i=1;i<n;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        a[u].pb({v,i});
        a[v].pb({u,i});
        w[i]=x;
        ed[i]={u,v};
    }
}
void QQ()
{
    string s;
    int u,v;

    while (1)
    {
        cin>>s;
        if (s[0]=='D') return;
        if (s[0]=='Q')
            query2();
        else
            query1();

    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {

        input();
        dfs(1,0);
        for (int i=1;i<=n;i++)
            chain[i]=0;
        for (int i=1;i<=nchain;i++)
            rchain[i]=0;
        hldbuild(1);
        setup();
        build(1,1,n);
        QQ();
    }
    return 0;
}
