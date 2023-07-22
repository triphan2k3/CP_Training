#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "IOIBIN.INP"
#define out "IOIBIN.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int dsu[N];
int n;

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
    dsu[x]+=dsu[y];
    dsu[y]=x;
}
int check(int u,int v)
{
    if (head(u)==head(v)) return 1;
    return 0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<N;i++)
        dsu[i]=-1;
    int x,y,z;
    while (n--)
    {
        cin>>x>>y>>z;
        if (z==1) add(x,y);
        else cout<<check(x,y)<<"\n";
    }
}
