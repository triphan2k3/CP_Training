#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "METERAIN.INP"
#define out "METERAIN.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;

ii a[N];
int m,n;

ii vec(ii a,ii b)
{
    return mp(b.X-a.X,b.Y-a.Y);
}

ll dot(ii a,ii b)
{
    return a.X*b.Y-a.Y*b.X;
}

ll area(ii a,ii b,ii c)
{
    ll x=(b.X-a.X)*(c.Y-a.Y)-(c.X-a.X)*(b.Y-a.Y);
    if (x<0) return -x;
    return x;
}

bool check(ii p)
{
    ll l=1,r=n;
    ii q=vec(a[1],p);
    while (r-l>1)
    {
        ll m=(l+r)>>1;
        ll x1=dot(vec(a[1],a[m]),q);
        if (x1<0) r=m;
        else l=m;
    }
    ll s1=area(p,a[1],a[l]);
    ll s2=area(p,a[l],a[r]);
    ll s3=area(p,a[r],a[1]);
    if (s1==0 || s2==0 ||s3==0) return false;
    ll s=s1+s2+s3;
    ll x=area(a[1],a[l],a[r]);
    if (s-x==0) return true;
    return false;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++)
        cin>>a[i].X>>a[i].Y;
    cin>>m;
    while (m--)
    {
        ll x,y;
        cin>>x>>y;
        if (check(mp(x,y)))
             cout<<"YES\n";
        else cout<<"NO\n";
    }
}
