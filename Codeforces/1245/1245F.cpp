/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1245F.INP"
#define out "1245F.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll c[35][35],mu[35];
ll solve(ll n)
{
    if (n<=1) return 0;
    vector<ll> a;
    while (n)
    {
        a.pb(n%2);
        n/=2;
    }
    ll res=0;
    n=a.size();
    for (int i=1;i<n;i++)
        for (int j=1;j<=n-i-1;j++)
            res+=c[i][n-1]*c[j][n-i-1];
    a.pb(0);
    int numbit1=1;
    reverse(a.begin(),a.end());
    res+=mu[n]-2;
    for (int i=2;i+1<n;i++)
        if (a[i]==1)
        {
            numbit1++;
            res+=mu[n-numbit1+1]-2;
            for (int j=1;j<=n-i;j++)
                res+=c[j][n-i]*2ll*(mu[n-numbit1-j+1]-1ll);
        }
    return res;
}
void prepare()
{
    for (int i=0;i<=32;i++)
        c[0][i]=1;
    for (int i=1;i<=32;i++)
        for (int j=1;j<=i;j++)
            c[j][i]=c[j][i-1]+c[j-1][i-1];
    mu[0]=1;
    for (int i=1;i<=32;i++)
        mu[i]=mu[i-1]+mu[i-1];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t;
    prepare();
    cin>>t;
    ll l,r;
    while (t--)
    {
        cin>>l>>r;
        ll st=solve(r);
        ll nd=solve(l-1);
        cout<<st<<"\n";
        cout<<nd<<"\n";
        cout<<st-nd<<"\n";
    }

}
