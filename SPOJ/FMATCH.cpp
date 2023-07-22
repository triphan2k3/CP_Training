#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "FMATCH.INP"
#define out "FMATCH.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int remind[N],avail[N],match[N],ok,m,n,p,sz;
void dfs(int u)
{
    for (int v:a[u])
    {
        if (avail[v]) continue;
        avail[v]=1;
        if (match[v]) dfs(match[v]);
        else ok=1;
        if (ok)
        {
            match[v]=u;
            return;
        }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n>>p;
    for (int i=1,u,v;i<=p;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
    }
    for (int i=1;i<=m;i++)
        remind[i]=i;
    sz=m;
    while (1)
    {
        int _sz=sz;
        for (int i=1;i<=n;i++)
            avail[i]=0;
        for (int i=sz;i>=1;i--)
        {
            ok=0;
            dfs(remind[i]);
            if (ok)
                remind[i]=remind[sz--];
        }
        if (sz==_sz) break;
    }
    cout<<m-sz;
}
