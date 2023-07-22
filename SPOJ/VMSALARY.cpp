#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VMSALARY.INP"
#define out "VMSALARY.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

vector<vector<int>> a;
int bit[2*N],val[2*N];
int fir[N],par[N],las[N],h[N];
int n,t;
ll res;
ii s[N];

int getsum(int x,int y)
{
    int res=0;
    while (y>=x)
    {
        if (y-(y&-y)>=x)
        {
            res+=bit[y];
            y-=y&-y;
        }
        else
        {
            res+=val[y];
            y--;
        }
    }
    return res;
}
void update(int x)
{
    while (x<=2*n)
    {
        bit[x]++;
        x+=x&-x;
    }
}
void dfs(int u)
{
    fir[u]=++t;
    for (int v:a[u])
    {
        h[v]=h[u]+1;
        dfs(v);
    }
    las[u]=++t;
}
void proces(int i)
{
    ll r=getsum(fir[i],las[i]);
    res+=(r*(r-1ll))>>1ll;
    update(fir[i]);
    val[fir[i]]=1;
}
bool cmp(ii x,ii y)
{
    if (x.X!=y.X)
        return x.X<y.X;
    return h[x.Y]<h[y.Y];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>s[1].X;
    a.resize(n+1);
    for (int i=2;i<=n;i++)
    {
        cin>>par[i]>>s[i].X;
        a[par[i]].pb(i);
    }
    for (int i=1;i<=n;i++)
        s[i].Y=i;
    dfs(1);
    sort(s+1,s+n+1,cmp);
    for (int i=1;i<=n;i++)
        proces(s[i].Y);
    cout<<res;
}
