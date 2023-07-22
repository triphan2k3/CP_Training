#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SPBINARY.INP"
#define out "SPBINARY.OUT"
#define bignum vector<int>
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
bignum f[601][2];
int n,k;

bignum operator +(bignum a,bignum b)
{
    bignum res;
    while (a.size()<b.size()) a.pb(0);
    while (b.size()<a.size()) b.pb(0);
    int now=0;
    for (int i=0;i<a.size();i++)
    {
        now+=a[i]+b[i];
        res.pb(now%10);
        now/=10;
    }
    if (now>0) res.pb(1);
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
            now+=10;
            car=1;
        } else car=0;
        res.pb(now);
    }
    while (res.size()>1 && res.back()==0) res.pop_back();
    return res;
}

void write(bignum s)
{
    while (!s.empty())
    {
        cout<<s.back();
        s.pop_back();
    }
    cout<<"\n";
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    scanf("%d",&n);
    scanf("%d",&k);
    f[1][1].pb(1);
    f[1][0].pb(1);
    f[0][1].pb(1);
    f[0][0].pb(1);

    for (int i=2;i<=n;i++)
    {
        f[i][0]=f[i-1][0]+f[i-1][1];
        f[i][1]=f[i-1][0]+f[i-1][1];
        if (i>k)
        {
            f[i][0]=f[i][0]-f[i-k-1][1];
            f[i][1]=f[i][1]-f[i-k-1][0];
        }

    }
    write(f[n][1]+f[n][0]);
}
