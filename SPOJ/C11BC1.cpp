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
const int K=57;
const ll MOD=790972;
const ll INF=(ll)1e18+7;
ii a[N];
ll f[K];
int n,k;

int proces(int fir,int sec)
{
    if (sec-fir+1<k) return 0;
    f[0]=1;
    for (int i=1;i<=k;i++) f[i]=0;
    for (int i=fir;i<=sec;i++)
        for (int j=k;j>=1;j--)
        {
            if (j>(i-fir+1)) continue;
            f[j]=(f[j-1]*a[i].Y+f[j])%MOD;
        }
    return f[k];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    ll res=proces(1,n);
    int pos=1;
    for (int i=2;i<=n+1;i++)
        if (a[i].first!=a[i-1].first)
        {
            res-=proces(pos,i-1);
            pos=i;
            if (res<0) res+=MOD;
        }
    cout<<res;
}
