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
int t,n,x,a,b;
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>x>>a>>b;
        if (a>b) swap(a,b);
        int y=x;
        int _a=a;
        a=max(1,a-x);
        x-=(_a-a);
        b=min(n,b+x);
        cout<<abs(a-b)<<"\n";
    }
}
