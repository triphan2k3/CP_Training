#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VDANGER.INP"
#define out "VDANGER.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[101][101];
int a[N],m,n,ans;
void floyd()
{
    for (int t=1;t<=n;t++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][t]+f[t][j]);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>f[i][j];
    floyd();
    for (int i=2;i<=m;i++)
        ans+=f[a[i-1]][a[i]];
    cout<<ans;
}
