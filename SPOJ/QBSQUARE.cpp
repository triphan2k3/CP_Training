#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBSQUARE.INP"
#define out "QBSQUARE.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N],f[N][N],g[N][N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int m,n;
    cin>>m>>n;
    int ans=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            int u;
            cin>>u;
            if (u) f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
              else g[i][j]=min(g[i-1][j],min(g[i][j-1],g[i-1][j-1]))+1;
            ans=max(ans,max(f[i][j],g[i][j]));
        }
    cout<<ans;
}
