#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VN_ZR_I.INP"
#define out "VN_ZR_I.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll c[33][33];
vector<ll> a;
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    c[0][0]=1;
    for (int i=1;i<=32;i++)
    {
        c[0][i]=1;
        for (int j=1;j<=i;j++)
            c[j][i]=c[j][i-1]+c[j-1][i-1];
    }
    ll n,k;
    while (scanf("%lld %lld",&n,&k)==2)
    {
        a.clear();
        while (n)
        {
            a.pb(n%2);
            n/=2;
        }
        ll res=0;
        for (ll i=1;i<a.size();i++)
        {
            ll t=0;
            ll cnt=0;
            for (ll j=i+1;j<=a.size()-1;j++)
                t+=c[i][j-1];
            for (ll j=a.size()-2;j>=0;j--)
            if (a[j]==0) cnt++;
            else
            {
                if (cnt>=i) continue;
                t+=c[i-cnt-1][j];
            }
            if (cnt==i) t++;
            res+=((i-1ll)/k+1ll)*t;
        }
        cout<<res<<"\n";
    }
}
