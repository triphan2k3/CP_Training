#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MNERED.INP"
#define out "MNERED.OUT"
using namespace std;
const int N=107;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,m;
int a[N][N];

int get(int x,int y,int i,int j)
{
    return a[i][j]-a[x-1][j]-a[i][y-1]+a[x-1][y-1];
}
int solve(int d,int r)
{
    int ans=0;
    for (int i=1;i+d-1<=n;i++)
        for (int j=1;j+r-1<=n;j++)
            ans=max(ans,get(i,j,i+d-1,j+r-1));
    return m-ans;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];

    int res=MOD;
    for (int i=1;i*i<=m;i++)
        if (m%i==0 && (m/i)<=n)
        {
            res=min(res,solve(i,m/i));
            res=min(res,solve(m/i,i));
        }
    cout<<res;
}
