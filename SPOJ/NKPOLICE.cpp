#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKPOLICE.INP"
#define out "NKPOLICE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a,child;
int num[N],low[N],tin[N],tou[N];
int m,n,T,cnt;

void dfs(int u,int p)
{
    tin[u]=++T;
    num[u]=low[u]=++cnt;
    for (int v:a[u])
    {
        if (v==p) continue;
        if (tin[v])
            low[u]=min(low[u],num[v]);
        else
        {
            child[u].pb(v);
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }

    }
    tou[u]=++T;
}
int findpar(int u,int v)
{
    //find x is par v and is child u
    int l=0;
    int r=child[u].size()-1;
    while (r-l>1)
    {
        int m=(r+l)>>1;
        if (tin[child[u][m]]>=tin[v]) r=m;
        else l=m;
    }
    if (tin[child[u][r]]<=tin[v]) return child[u][r];
    return child[u][l];
}
int ischild(int u,int v)
{
    //v is child of u
    if (tin[u]>tin[v]) return 0;
    if (tou[u]<tou[v]) return 0;
    return 1;
}
int sol1()
{
    int u,v,x,y;
    cin>>u>>v>>x>>y;
    if (ischild(y,x)) swap(x,y);
    if (low[y]<num[y]) return 1;
    if (ischild(y,u)==ischild(y,v)) return 1;
    return 0;

}
int sol2()
{
    int u,v,w;
    cin>>u>>v>>w;
    if (!ischild(w,u) && !ischild(w,v)) return 1;
    if (ischild(w,u)  &&  ischild(w,v))
    {
        int x=findpar(w,u);
        int y=findpar(w,v);
        if (x==y) return 1;
        if (low[x]<num[w] && low[y]<num[w]) return 1;
        return 0;
    }
    if (ischild(w,u)) swap(u,v);
    //v is child of w
    int x=findpar(w,v);
    if (low[x]<num[w]) return 1;
    return 0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    a.resize(n+1);
    child.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int t,tt,res;
    cin>>t;
    for (int u=1;u<=n;u++)
        if (!num[u]) dfs(u,0);
    while (t--)
    {
        cin>>tt;
        if (tt==1) res=sol1();
        else res=sol2();
        if (res) cout<<"yes\n"; else cout<<"no\n";
    }

}
