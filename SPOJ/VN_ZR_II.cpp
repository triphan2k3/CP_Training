#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VN_ZR_II.INP"
#define out "VN_ZR_II.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll f[34][34];
ll l[32];
ll lt(int i)
{
    if (i==-1) return 1ll;
    return l[i];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    l[0]=1;
    for (int i=1;i<=32;i++)
        l[i]=l[i-1]+l[i-1];

    for (int i=1;i<=33;i++) //k
    {
        for (int j=2;j<=33;j++)
        {
            f[j][i]=f[j-1][i];
            for (int t=1;t<=j-1;t++)
                f[j][i]+=f[j-t-1][i]+lt(j-t-2)*((t-1)/i+1);
        }
    }
    //f[i][j] la so chu so 0 duoc to mau voi k=j va so luong bit=i

    ll n,k;
    while (scanf("%lld %lld",&n,&k)==2)
    {
        vector<int> a;
        while (n)
        {
            a.pb(n%2);
            n/=2;
        }
        ll res=0;
        if (k>32) k=32;
        for (int i=1;i<a.size();i++)
            res+=f[i][k];

        ll now=0;
        ll cnt=0;
        for (int i=a.size()-2;i>=0;i--)
        if (a[i]==0) now++;
        else
        {
            //now++;
            res+=cnt*lt(i);
            //"hien tai la _ _ _ _ 0 [j so 0] 1 _ _ _"
            for (int j=0;j<=i;j++)
                res+=((now+j)/k+1)*lt(i-j-1)+f[i-j][k];
                //res+=((now+j-1ll)/k+1)+f[i-j][k]
            if (now>0)
            cnt+=(now-1)/k+1;
            now=0;
        }
        res+=cnt;
        if (now>0)
            res+=(now-1)/k+1;
        cout<<res<<"\n";

    }
}
