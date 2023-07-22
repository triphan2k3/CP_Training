#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PBCGANGS.INP"
#define out "PBCGANGS.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int dsu[N],thu[N];
int n,m;
int head(int u)
{
    if (dsu[u]<0) return u;
    return dsu[u]=head(dsu[u]);
}

void add(int u,int v)
{
    int x=head(u);
    int y=head(v);
    if (x==y) return;
    if (x>y) swap(x,y);
    dsu[x]+=dsu[y];
    dsu[y]=x;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        dsu[i]=-1;

    for (int i,u,v;i<=m;i++)
    {
        char k;
        cin>>k>>u>>v;
        if (k=='F') add(u,v);
        else
        {
            if (thu[u]) add(thu[u],v);
            if (thu[v]) add(thu[v],u);
            thu[u]=v;
            thu[v]=u;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        if (dsu[i]<0) ans++;

    cout<<ans;
}
