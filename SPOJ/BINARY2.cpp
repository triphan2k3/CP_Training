#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BINARY2.INP"
#define out "BINARY2.OUT"
using namespace std;
const int N=(int)1e6+7;
const int MOD=(int)1e9;
const ll INF=(ll)1e18+7;
int f[N][2];
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    f[0][1]=1;
    f[0][0]=1;
    f[1][1]=1;
    f[1][0]=1;
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);

    for (int i=2;i<=n;i++)
    {
        f[i][1]=f[i-1][0]+f[i-1][1];
        f[i][0]=f[i-1][0]+f[i-1][1];
        if (i>k)
        {
            f[i][1]-=f[i-k-1][0];
            f[i][0]-=f[i-k-1][1];
        }
        if (f[i][1]<0) f[i][1]+=MOD;
        if (f[i][1]>MOD) f[i][1]-=MOD;
        if (f[i][0]<0) f[i][0]+=MOD;
        if (f[i][0]>MOD) f[i][0]-=MOD;
    }
    cout<<(f[n][0]+f[n][1])%MOD;

}
