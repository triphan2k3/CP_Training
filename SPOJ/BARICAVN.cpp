#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,ii>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BARICAVN.INP"
#define out "BARICAVN.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct data
{
    int x,y,w,id;
};
bool cmp(data a,data b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
data a[N];
int pos[N],n,k;
int fx[N],fy[N],f[N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].w;
    fx[a[1].x]=a[1].w;
    fy[a[1].y]=a[1].w;
    for (int i=1;i<=n;i++)
        a[i].id=i;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
        pos[a[i].id]=i;
    f[pos[1]]=a[pos[1]].w;
    for (int i=pos[1]+1;i<=pos[n];i++)
    {
        if (fx[a[i].x]>=k)
            f[i]=max(f[i],fx[a[i].x]-k+a[i].w);
        if (fy[a[i].y]>=k)
            f[i]=max(f[i],fy[a[i].y]-k+a[i].w);
        fx[a[i].x]=max(fx[a[i].x],f[i]);
        fy[a[i].y]=max(fy[a[i].y],f[i]);
    }
    cout<<f[pos[n]];
}
