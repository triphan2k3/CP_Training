#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e2+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int s[N][N][N];
int a[N][N][N];
int ans,n;
int getsum(int x, int y,int z,int sz)
{
    return s[x+sz][y+sz][z+sz]-s[x-1][y+sz][z+sz]-s[x+sz][y+sz][z-1]-s[x+sz][y-1][z+sz]+
          +s[x-1][y-1][z+sz]+s[x+sz][y-1][z-1]+s[x-1][y+sz][z-1]-s[x-1][y-1][z-1];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        ans=-MOD;
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    cin>>a[i][j][k];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    s[i][j][k]=s[i][j-1][k]+s[i][j][k-1]+s[i-1][j][k]+a[i][j][k]
                              -s[i-1][j-1][k]-s[i][j-1][k-1]-s[i-1][j][k-1]+s[i-1][j-1][k-1];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    for (int v=0;v<n;v++)
                    {
                        if (n-max(i,max(j,k))<v) break;
                        ans=max(ans,getsum(i,j,k,v));
                    }
        cout<<ans<<"\n";
    }
}
