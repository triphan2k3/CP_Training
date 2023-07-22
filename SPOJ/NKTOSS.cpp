#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKTOSS.INP"
#define out "NKTOSS.OUT"
#define bignum vector<int>
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e8;
const ll INF=(ll)1e18+7;
bignum lt[10001];
bignum  f[10001][2];
bignum operator +(bignum a,bignum b)
{
    bignum res;
    while (a.size()<b.size()) a.pb(0);
    while (b.size()<a.size()) b.pb(0);
    int now=0;
    for (int i=0;i<a.size();i++)
    {
        now+=a[i]+b[i];
        res.pb(now%MOD);
        now/=MOD;
    }
    if (now>0) res.pb(now);
    return res;
}
bignum operator -(bignum a,bignum b)
{
    bignum res;
    while (a.size()<b.size()) a.pb(0);
    while (b.size()<a.size()) b.pb(0);
    int now=0;
    int car=0;
    for (int i=0;i<a.size();i++)
    {
        now=a[i]-b[i]-car;
        if (now<0)
        {
            now+=MOD;
            car=1;
        } else car=0;
        res.pb(now);
    }
    while (res.size()>1 && res.back()==0) res.pop_back();
    return res;
}

void write(bignum s)
{
    cout<<s.back();
    s.pop_back();
    while (!s.empty())
    {
        int t=s.back();
        if (t==0) cout<<"00000000";
        else
        {
            while (t*10<MOD) cout<<"0",t*=10;
            cout<<s.back();
        }
        s.pop_back();
    }
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    int n,k;
    cin>>n>>k;
    lt[0].pb(1);
    for (int i=1;i<=n;i++)
        lt[i]=lt[i-1]+lt[i-1];

    f[k][1].pb(1);
    f[k][0].pb(0);
    for (int i=k+1;i<=n;i++)
    {
        f[i][0]=f[i-1][0]+f[i-1][1];
        f[i][1]=f[i-1][0]+f[i-1][1]+lt[i-k-1];
        if (i>2*k)
            f[i][1]=f[i][1]-f[i-k][0];

    }
    bignum res=f[n][0]+f[n][1];
    write(res);
}
