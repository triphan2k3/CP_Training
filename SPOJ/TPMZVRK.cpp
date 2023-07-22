#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "TPMZVRK.INP"
#define out "TPMZVRK.OUT"
using namespace std;
const ll MOD=15111992;
ll lt(int i)
{
    if (i==0) return 1;
    ll res=1;
    for (int j=1;j<=i;j++ )
        res=(res+res)%MOD;
    return res;
}
ll solve(string s)
{
    int en=s.size()-1;
    ll res=0;
    for (int i=s.size()-1;i>=0;i--)
    {
        ll val=0;
        for (ll j=i-1;j>=0;j--)
            if (s[j]=='1') val=(val+lt(i-1-j))%MOD;
        res+=val*(lt(en-i));
        if (s[i]=='1') res+=lt(en-i);
        res%=MOD;
    }
    return res;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    string a,b;
    cin>>a>>b;
    ll res=solve(b);
    res=res-solve(a);
    res%=MOD;
    cout<<res;
}
