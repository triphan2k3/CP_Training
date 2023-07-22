#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MPILOT.INP"
#define out "MPILOT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ii a[10001];
int f[2][10001];
int n;

int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].X>>a[i].Y;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i/2;j++)
        {
            f[i%2][j]=f[(i+1)%2][j]+a[i].Y;
            if (j==0) continue;
            int t=f[(i+1)%2][j]==0 ? f[(i+1)%2][j-1]+a[i].X:min(f[(i+1)%2][j]+a[i].Y,f[(i+1)%2][j-1]+a[i].X);
            f[i%2][j]=t;
        }
    cout<<f[n%2][n/2];

}
