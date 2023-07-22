#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VMSWAP.INP"
#define out "VMSWAP.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
int f[N][N],g[N][N];
int all,n,ans;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            f[i][j]=a[j]<i ? f[i][j-1]+1:f[i][j-1];
            g[i][j]=a[j]>i ? g[i][j-1]+1:g[i][j-1];
        }
    for (int i=1;i<=n;i++)
        all+=g[a[i]][i];

    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            int up=g[a[i]][j]-g[a[i]][i-1]+f[a[j]][j]-f[a[j]][i];
            int dw=f[a[i]][j]-f[a[i]][i-1]+g[a[j]][j]-g[a[j]][i];
            ans=min(ans,up-dw);
        }
    cout<<all+ans;
}
