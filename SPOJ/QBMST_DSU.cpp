#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBMST.INP"
#define out "QBMST.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct data
{
    int u,v,w;
};
data a[N],res[N];
int dsu[N],m,n,ans,T;
bool cmp(data a,data b)
{
    return a.w<b.w;
}

int head(int u)
{
    if (dsu[u]<0) return u;
    return dsu[u]=head(dsu[u]);
}
void add(data t)
{
    int x=head(t.u);
    int y=head(t.v);
    if (x==y) return;
    ans+=t.w;
    if (dsu[x]<dsu[y]) swap(x,y);
    dsu[x]+=dsu[y];
    dsu[y]=x;
    //res[++T]=t;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        a[i+m].u=a[i].v;
        a[i+m].v=a[i].u;
        a[i+m].w=a[i].w;
    }
    for (int i=1;i<=n;i++)
        dsu[i]=-1;
    sort(a+1,a+2*m+1,cmp);
    for (int i=1;i<=2*m;i++)
        add(a[i]);
    /*
    for (int i=1;i<n;i++)
        cout<<res[i].u<<" "<<res[i].v<<"\n";
    */
    cout<<ans;
}
