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
#define inp "1257C.INP"
#define out "1257C.OUT"
using namespace std;
const int N=(int)5e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,t;
vector<int> a[N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1,x;i<=n;i++)
        {
            cin>>x;
            a[x].pb(i);
        }
        int ans=MOD;
        for (int v=1;v<=n;v++)
            for (int i=1;i<a[v].size();i++)
                ans=min(ans,a[v][i]-a[v][i-1]+1);
        if (ans==MOD) cout<<"-1\n";
        else cout<<ans<<"\n";
        for (int i=1;i<=n;i++)
            a[i].clear();
    }
}
