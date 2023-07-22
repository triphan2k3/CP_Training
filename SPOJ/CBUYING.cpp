#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ii a[N];
ll n,b,ans;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>b;
    for (int i=1;i<=n;i++)
        cin>>a[i].X>>a[i].Y;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        if (b<a[i].X) break;
        else
        {
            if (b/a[i].X<a[i].Y)
            {
                ans+=b/a[i].X;
                break;
            }
            ans+=a[i].Y;
            b-=a[i].X*a[i].Y;
        }
    cout<<ans;
}
