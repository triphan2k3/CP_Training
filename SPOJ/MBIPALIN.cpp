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
const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll m,n,fir,las,ma;
ll a[N],b[N];
ll rever(ll i)
{
    ll j=0;
    ll x=i;
    if (i==0) return j;
    while (i)
    {
        j=j*10ll+i%10ll;
        i/=10ll;
    }
    while (x<fir)
    {
        x*=10;
        j*=10ll;
    }
    return j;
}
void update(ll i,int c)
{
    if (c) b[i]++;
    else a[i]++;
}
void add(ll i,int c)
{
    ll j=rever(i);
    if (n%4==0)
    {
        //cout<<i*las+j<<" "<<(i*las+j)%m<<"\n";
        ll modulo=(i*las+j)%m;
        update(modulo,c);
        return;
    }
    for (ll giua=0;giua<=9;giua++)
    {
        //cout<<i*las*10ll+giua*las+j<<" "<<(i*las*10ll+giua*las+j)%m<<"\n";
        ll modulo=(i*las*10ll+giua*las+j)%m;
        update(modulo,c);
    }
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    if (n==2)
    {
        ll res=0;
        for (ll i=10;i<=99;i++)
            if (i%m==0) res++;
        cout<<res;
        return 0;
    }
    ma=fir=1;
    ll nhan=1;
    for (int i=1;i<=n/2;i++)
        nhan*=10;

    for (int i=1;i<=n/4;i++)
        ma*=10;
    for (int i=1;i<n/4;i++)
        fir*=10;
    las=ma;
    for (int i=fir;i<las;i++)
        add(i,0);

    for (int i=0;i<las;i++)
        add(i,1);
    ll res=a[0]*b[0];
    for (int i=1;i<m;i++)
    {
        ll tmp=(i*nhan)%m;
        if (tmp==0) tmp=m;
        res+=a[i]*b[m-tmp];
    }
    //add(10,1);
    cout<<res;
}
