#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BCDIV.INP"
#define out "BCDIV.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll f[30][30];
int t,n,k;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    f[0][0]=1;
    for (ll i=1;i<=25;i++)
        for (ll j=1;j<=i;j++)
            f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        cout<<f[n][k]<<"\n";
    }
}
