#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "KPASS.INP"
#define out "KPASS.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll f[33][2];
ll sum[33];
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    ll n,k,x;
    cin>>n>>x>>k;

    f[1][0]=f[1][1]=f[0][1]=f[0][0]=1;
    sum[0]=1;
    sum[1]=2;
    for (int j=2;j<=n;j++)
    {
        f[j][1]=f[j-1][0]+f[j-1][1];
        f[j][0]=sum[j-1];
        if (j>k)
            f[j][0]-=sum[j-k-1];
        sum[j]=sum[j-1]+f[j][1];
    }
    ll dem=0;
    vector<int> a;
    for (int i=n;i>=1;i--)
    {
        ll numz=sum[i-1];
        if (i-k+dem>0) numz-=sum[i-k+dem-1];
        if (numz>=x)
        {
            a.pb(0);
            dem++;
            continue;
        }
        dem=0;
        x-=numz;
        a.pb(1);
    }
    ll res=0;
    for (int i=0;i<a.size();i++)
        res=res*2+a[i];

    a.clear();
    for (int i=1;i<=n;i++)
    {
        a.pb(res%10);
        res/=10;
    }
    for (int i=a.size()-1;i>=0;i--)
        cout<<a[i]<<' ';
}
