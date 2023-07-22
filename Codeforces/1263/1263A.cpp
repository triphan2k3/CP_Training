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
#define inp "1263A.INP"
#define out "1263A.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,g,b,r;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>g>>b>>r;
        int ma=max(g,max(b,r));
        if (ma>b+r+g-ma)
        {
            cout<<b+r+g-ma<<"\n";
            continue;
        }
        cout<<(g+b+r)/2<<"\n";
    }
}
