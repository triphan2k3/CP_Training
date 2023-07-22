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
#define inp "1263C.INP"
#define out "1263C.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,n;
vector<int> a;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        a.clear();
        a.pb(0);
        for (int i=1;i*i<=n;i++)
        {
            a.pb(i);
            a.pb(n/i);
        }
        sort(a.begin(),a.end());
        int ans=1;
        for (int i=1;i<a.size();i++)
            if (a[i]!=a[i-1]) ans++;
        cout<<ans<<"\n";
        cout<<a[0]<<" ";
        for (int i=1;i<a.size();i++)
            if (a[i]!=a[i-1])
                cout<<a[i]<<" ";
        cout<<"\n";
    }
}
