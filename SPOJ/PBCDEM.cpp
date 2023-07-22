#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define big vector<ll>
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll BASE=(int)1e9;
const ll INF=(ll)1e18+7;
ll n;
big f[5000];

big operator + (big a,big b)
{
    big c;
    while (a.size()<b.size()) a.pb(0);
    while (a.size()>b.size()) b.pb(0);
    int sz=a.size();
    ll cnt=0;
    for (int i=0;i<sz;i++)
    {
        ll sum=a[i]+b[i]+cnt;
        if (sum>=BASE)
        {
            sum-=BASE;
            cnt=1;
        } else cnt=0;
        c.pb(sum);
    }
    if (cnt) c.pb(cnt);
    return c;
}

int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n;
    f[0].pb(1);

    for (int i=1;i<n;i++)
        for (int j=n;j>=i;j--)
                f[j]=f[j]+f[j-i];
            //else f[j][i%2]=f[j][(i+1)%2];

    //cout<<f[n][(n-1)%2];
    cout<<f[n][f[n].size()-1];
    for (int i=f[n].size()-2;i>=0;i--)
    {
        ll tmp=f[n][i];
        tmp*=10;
        while (tmp<BASE)
        {
            cout<<0;
            tmp*=10;
        }
        cout<<f[n][i];
    }

}
