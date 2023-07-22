#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "ASSIGN1.INP"
#define out "ASSIGN1.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N],match[N],visit[N],remain[N];
int ok,n,ans;
void dfs(int u,int val)
{
    for (int i=1;i<=n;i++)
    if (a[u][i]<=val)
    {
        if (visit[i]) continue;
        visit[i]=1;
        if (!match[i]) ok=1;
        else dfs(match[i],val);
        if (ok)
        {
            match[i]=u;
            return;
        }
    }
}
bool check(int val)
{
    for (int i=1;i<=n;i++)
        match[i]=visit[i]=0;
    for (int i=1;i<=n;i++)
        remain[i]=i;
    int sz=n;
    while (1)
    {
        int _sz=sz;
        for (int i=1;i<=n;i++)
            visit[i]=0;
        for (int i=sz;i>=1;i--)
        {
            ok=0;
            dfs(remain[i],val);
            if (ok)
                remain[i]=remain[sz--];
        }
        if (_sz==sz) break;
    }
    for (int i=1;i<=n;i++)
        if (!match[i]) return 0;
    return 1;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    int r=0,l=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        r=max(r,a[i][j]);
    }
    ans=r;
    while (r>=l)
    {
        int mid=(r+l)>>1;
        if (check(mid))
        {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<<ans;
}
