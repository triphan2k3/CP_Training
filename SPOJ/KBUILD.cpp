#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "KBUILD.INP"
#define out "KBUILD.OUT"
using namespace std;
const int N=(int)2e5+7;

vector<vector<int>> a;
int nchain=1,cpos,n;
int root[N],chil[N],chain[N],par[N],pos[N],h[N];
int ptab[N][20];
int it[4*N];
void dfs(int u,int p)
{
    chil[u]=1;
    for (int v:a[u])
    {
        if (v==p) continue;
        par[v]=u;
        h[v]=h[u]+1;
        dfs(v,u);
        chil[u]+=chil[v];
    }
}
void hld(int u)
{
    if (root[nchain]==0) root[nchain]=u;
    chain[u]=nchain;
    pos[u]=++cpos;
    int nn=-1; //nextnode
    int ns=0;  //nodesize
    for (int v:a[u])
    {
        if (chil[v]<=ns || v==par[u]) continue;
        ns=chil[v];
        nn=v;
    }
    if (nn==-1) return;
    hld(nn);
    for (int v:a[u])
    {
        if (v==par[u] || v==nn) continue;
        nchain++;
        hld(v);
    }
}
void lcasetup()
{
    for (int i=1;i<=n;i++)
        ptab[i][0]=par[i];
    for (int k=1;k<=17;k++)
        for (int i=1;i<=n;i++)
            ptab[i][k]=ptab[ptab[i][k-1]][k-1];
}
int lca(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    for (int i=17;i>=0;i--)
        if (h[u]-(1<<i)>=h[v]) u=ptab[u][i];

    for (int i=17;i>=0;i--)
    if (ptab[u][i]!=ptab[v][i])
    {
        u=ptab[u][i];
        v=ptab[v][i];
    }
    if (u==v) return u;
    return par[u];
}
void update(int pos,int left,int right,int l,int r)
{
    if (left>r || right<l) return;
    if (l<=left && r>=right) { it[pos]=1; return;}
    int mid=(left+right)>>1;
    update(pos<<1,left,mid,l,r);
    update((pos<<1)+1,mid+1,right,l,r);
}
int getmax(int pos,int left,int right,int m)
{
    if (left>m || right<m) return 0;
    if (left==right || it[pos]==1) return it[pos];
    int mid=(left+right)>>1;
    int m1=getmax(pos<<1,left,mid,m);
    int m2=getmax((pos<<1)+1,mid+1,right,m);
    return max(m1,m2);
}
void proces(int u,int v)
{
    while (chain[u]!=chain[v])
    {
        int r=root[chain[u]];
        update(1,1,n,pos[r],pos[u]);
        u=par[r];
    }
    update(1,1,n,pos[v],pos[u]);
}
void query(int u,int v)
{
    int r=lca(u,v);
    proces(u,r);
    proces(v,r);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int u,v;
    a.resize(n+1);
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,0);
    hld(1);
    lcasetup();
    int q;
    cin>>q;
    while (q--)
    {
        cin>>u>>v;
        query(u,v);
    }
    int res=0;
    for (int i=1;i<=n;i++)
        res+=getmax(1,1,n,i);
    cout<<n-res;
}
