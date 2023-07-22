#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "DISNEY2.INP"
#define out "DISNEY2.OUT"
using namespace std;
const int N=207;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[N][N];
int a[N][N];
int n;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];

    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<i;j++)
            f[i][j]=f[i-1][j]+a[i-1][i];
        f[i][i]=MOD;
        for (int k=1;k<i;k++)
            f[i][i-1]=min(f[i][i-1],f[i-1][k]+a[k][i]);
    }
    int ans=MOD;
    for (int i=1;i<=n;i++)
        ans=min(ans,f[n][i]+a[n][1]+a[i][1]);
    cout<<ans;
}
