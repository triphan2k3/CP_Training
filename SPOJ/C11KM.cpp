#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "C11KM.INP"
#define out "C11KM.OUT"
using namespace std;
const int N=(int)1e3+7;
const int oo=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n;
int f[N][N];
int a[N];
int maxf;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=0;i<=n;i++)
        for (int j=0;j<=n+1;j++)
            f[i][j]=oo;
    f[0][0]=0;
    for (int i=1;i<=n;i++)
    if (a[i]<=100)
    {
        for (int j=0;j<=maxf;j++)
            f[i][j]=min(f[i-1][j]+a[i],f[i-1][j+1]);
    }
    else
    {
        f[i][0]=f[i-1][1];
        maxf++;
        for (int j=1;j<=maxf;j++)
            f[i][j]=min(f[i-1][j-1]+a[i],f[i-1][j+1]);
    }
    int res=oo;
    for (int i=0;i<=maxf;i++)
        res=min(res,f[n][i]);
    cout<<res;
}
