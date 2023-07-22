#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKPATH.INP"
#define out "NKPATH.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9;
const ll INF=(ll)1e18+7;
int m,n;
int a[N][N],f[N][N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++)
        f[i][1]=1;

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            for (int x=1;x<=i;x++)
                for (int y=1;y<=j;y++)
                    {
                        if (x+y==i+j) continue;
                        if (y==n) continue;
                        if (__gcd(a[i][j],a[x][y])==1) continue;
                        f[i][j]+=f[x][y];
                        if (f[i][j]>=MOD)
                            f[i][j]-=MOD;

                    }
    int ans=0;
    for (int i=1;i<=m;i++)
        {
            ans+=f[i][n];
            if (ans>=MOD) ans-=MOD;
        }
    cout<<ans;
}
