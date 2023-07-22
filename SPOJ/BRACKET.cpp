#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BRACKET.INP"
#define out "BRACKET.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ll f[61][31][2];
int main()
{


    ll n,k;
    //cin>>n>>k;
    scanf("%lld",&n);
    scanf("%lld",&k);
    f[n][1][0]=1;
    for (ll i=n-1;i>=1;i--)
        for (ll j=k;j>=0;j--)
        {
            if (j>0)
            {
                f[i][j][j==k]+=f[i+1][j-1][0];
                f[i][j][1]+=f[i+1][j-1][1];
            }
            if (j<k)
            {
                f[i][j][0]+=f[i+1][j+1][0];
                f[i][j][1]+=f[i+1][j+1][1];
            }
        }
    cout<<f[1][0][1];
    string s;
    cin>>s;
    s="D"+s;
    ll pre=1;
    ll temp=1;
    ll res=0;
    ll ck=0;
    for (ll i=2;i<=n;i++)
    {
        temp+=(s[i]=='(') ? 1:-1;
        if (temp+2<=k && temp<pre)
        {
            res+=f[i+1][temp+2][1];
            if (ck) res+=f[i+1][temp+2][0];
        }
        pre=temp;
        ck|=pre==k;
    }
    cout<<"\n"<<res+1ll;
}
