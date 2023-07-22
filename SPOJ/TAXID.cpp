#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "TAXID.INP"
#define out "TAXID.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll f[100];
vector<ll> a;
ll n,m,p,q;
ll c[100],lt[100];
char ch[100];
ll lim,total,t,len;
ll ma;
void setup()
{
    while (n)
    {
        a.pb(n%36);
        n/=36;
        ma=max(ma,a.back());
    }
    lim=a.size();
    reverse(a.begin(),a.end());
}
void dp()
{
    t=(p+1)/2;
    f[1]=c[t]-c[t-1];
    lt[0]=1;
    for (int i=1;i<=lim;i++)
        lt[i]=lt[i-1]*(ll)c[t];
    for (int i=2;i<=lim;i++)
        f[i]=f[i-1]*c[t-1]+lt[i-1]*(c[t]-c[t-1]);
}
void allavail()
{
    total=0;
    ll ck=0;
    for (ll i=0;i<lim;i++)
    if (a[i]==0) continue;
    else
    {
        if (ck)
            total+=min(a[i],c[t])*lt[lim-i-1];
        else
        if (a[i]>=c[t-1])
        {
            total+=c[t-1]*f[lim-i-1]+(min(a[i],c[t])-c[t-1])*lt[lim-i-1];
            ck=1;
        }
        else total+=a[i]*f[lim-i-1];

        if (a[i]>=c[t]) return;
    }
    if (a.back()<c[t-1] && (ck==0)) return;
    total++;
}
void proces()
{
    ll ck=0,z,tp;
    for (ll i=len;i>=1;i--)
    {
        ll ft=(i==len) ? 1:0;
        for (ll j=ft; ;j++)
        {
            if (ck || (j>=c[t-1]))
                tp=lt[i-1];
            else tp=f[i-1];
            if (q>tp) q-=tp;
            else
            {
                z=j;
                break;
            }
        }
        if (z>=c[t-1]) ck=1;
        cout<<ch[z];
    }

}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>p>>q;
    for (int i=1;i*2<=(m-1);i++)
        cin>>c[i];

    c[(m-1)/2+1]=36;
    c[0]=1;

    for (int i=0;i<36;i++)
        ch[i]=(i<10) ? i+'0' : i-10+'a';

    setup();
    dp();
    allavail();
    if (p%2==0) q=total-q+1ll ;
    len=1;
    for ( ; ;len++)
        if (f[len]>=q) break;
    q-=f[len-1];
    proces();
}
