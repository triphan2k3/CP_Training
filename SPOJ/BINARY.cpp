#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BINARY.INP"
#define out "BINARY.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll c[35][35];
ll a[35];
ll n,k;
void solve()
{
    vector<ll> d;
    ll res=0;
    ll dem=0;
    while (n)
    {
        if (n%2==0) dem++;
        d.pb(n%2);
        n/=2;
    }
    if ((k>=d.size() && k!=1) ||k<0)
    {
        cout<<0<<"\n";
        return;
    }
    ll siz=d.size();
    for (ll i=k+1;i<siz;i++)
        res+=c[k][i-1];
    ll num0=0;
    ll i;
    for (i=siz-2;i>=0;i--)
    if (d[i]==0) num0++;
    else
    {
        if (num0>=k) break;
        res+=c[k-num0-1][i];
    }
    if (dem==k) res++;
    if (k==1) res++;
    cout<<res<<"\n";
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);

    c[0][0]=1;
    for (ll i=1;i<=33;i++)
    {
        c[0][i]=1;
        for (ll j=1;j<=i;j++)
            c[j][i]=c[j][i-1]+c[j-1][i-1];
    }
    /*
    while (scanf("%lld",&n)==1)
    {
        scanf("%lld",&k);
            solve(n,k);
    }
    */
    while (scanf("%lld %lld",&n,&k)==2)
    {
        if (n==0)
        {
            if (k==1) printf("1\n");
            else printf("0\n");
        }
        else solve();
    }
}
