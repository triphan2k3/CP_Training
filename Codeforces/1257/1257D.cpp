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
#define inp "1257D.INP"
#define out "1257D.OUT"
using namespace std;
const int N=(int)5e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ii a[N];
int pre[N],p[N];
int t,m,n;

int findnp(int l,int val)
{
    int r=m;
    if (a[r].X<val) return -1;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (a[mid].X>=val) r=mid;
        else l=mid;
    }
    if (a[l].X>=val) return l;
    return r;
}
int solve()
{
    int post=1;
    int ans=0;
    while (post<=n)
    {
        int sl=0;
        int high=1;
        while (1)
        {
            if (post>n) break;
            high=findnp(high,p[post]);
            if (high==-1) return high;
            if (pre[high]<sl+1) break;
            sl++;
            post++;
        }
        ans++;
    }
    return ans;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>p[i];
        cin>>m;
        for (int i=1;i<=m;i++)
            cin>>a[i].X>>a[i].Y;
        sort(a+1,a+m+1);
        pre[m+1]=0;
        for (int i=m;i>=1;i--)
            pre[i]=max(pre[i+1],a[i].Y);
        cout<<solve()<<"\n";
    }
}
