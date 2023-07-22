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
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    ll n,m,s=0,ma=0;
    cin>>n;
    for (ll i=1;i<=n;i++)
    {
        cin>>m;
        s+=m;
        ma=max(ma,m);
    }
    if (s%2==0 && ma*2<=s) cout<<"YES";
    else cout<<"NO";
}
