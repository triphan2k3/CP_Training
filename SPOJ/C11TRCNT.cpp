#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "C11TRCNT.INP"
#define out "C11TRCNT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n;
ll x[N],y[N];
int res[N];

ll dot(ii a,ii b)
{
    return a.X*b.Y-b.X*a.Y;
}
ii vec(int i,int j)
{
    return {x[j]-x[i],y[j]-y[i]};
}
bool ok(int i,int j,int k)
{
    ll x=dot(vec(i,j),vec(i,k));
    if (x==0) return true;
    return false;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
                {
                    if (j==i || k==i) continue;
                    if (ok(i,j,k)) continue;
                        res[i]++;
                    if (i<j && j<k)
                        ans++;
                }
    cout<<ans<<" ";
    ans=1;
    for (int i=2;i<=n;i++)
        if (res[ans]>res[i]) ans=i;
    cout<<ans;
}
