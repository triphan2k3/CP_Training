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
const int N=(int)1e4+17;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],f[N],ans,n,k;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>k;
    n+=10;
    for (int i=11;i<=n;i++)
        cin>>a[i];

    for (int i=11;i<=n;i++)
        f[i]=INT_MIN;
    for (int i=11;i<=n;i++)
        for (int j=1;j<=k;j++)
            f[i]=max(f[i],f[i-j]+a[i]);

    for (int i=11;i<=n;i++)
        ans=max(ans,f[i]);
    cout<<ans;
}
