#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MZVRK.INP"
#define out "MZVRK.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ll solve(ll a)
{
    vector<ll> v;
    v.clear();
    ll t=a;
    while (a)
    {
        v.pb(a%2);
        a>>=1ll;
    }
    ll res=0;
    for (int i=0;i<v.size();i++)
        res+=(1ll<<i)*(t>>(i+1ll))+(t&(1ll<<i));
    return res;
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    ll a,b;
    cin>>a>>b;
    ll res=solve(b);
    res-=solve(a-1ll);
    cout<<res;
}
