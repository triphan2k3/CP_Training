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
#define inp "TEST.INP"
#define out "TEST.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    int n,m;
    cin>>n>>m;
    int s=0,ma=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
        ma=max(ma,a[i]);
    }
    if (ma*n-s>m) cout<<ma<<" ";
    else
    {
        int t=m-(ma*n-s);
        t=(t+n-1)/n;
        cout<<t+ma<<" ";
    }
    cout<<ma+m;
}
