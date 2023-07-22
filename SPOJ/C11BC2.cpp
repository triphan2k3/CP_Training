#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "C11BC2.INP"
#define out "C11BC2.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int dsu[N];
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
    if (dsu[x]<dsu[y]) swap(x,y);
    dsu[y]+=dsu[x];
    dsu[x]=y;
}

int check(int u,int v)
{
    int x=head(u);
    int y=head(v);
    if (x==y) return 1;
    return 0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        dsu[i]=-1;
    for (int i=2,x,k;i<=n;i++)
    {
        cin>>x>>k;
        if (k==1) add(i,x);
    }

    while (q--)
    {
        int u,v;
        cin>>u>>v;
        if (!check(u,v)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
