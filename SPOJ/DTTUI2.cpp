#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "DTTUI2.INP"
#define out "DTTUI2.OUT"
using namespace std;
const int N=(int)1e4+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a;
int f[N];
int n,m;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int w,v,s;
        cin>>w>>v>>s;
        int t=1;
        while (s>=t)
        {
            a.pb({w*t,v*t});
            s-=t;
            t+=t;
        }
        if (s)
            a.pb({w*s,v*s});
    }
    n=a.size();
    for (ii u:a)
        for (int j=m;j>=1;j--)
        {
            if (j<u.X) break;
            f[j]=max(f[j],f[j-u.X]+u.Y);
        }
    cout<<f[m];
}
