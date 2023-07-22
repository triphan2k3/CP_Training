#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MTWALK.INP"
#define out "MTWALK.OUT"
using namespace std;
const int N=105;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int m,n,num;
int ck[N][N];
int a[N][N];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int inpath(int v,int l,int r)
{
    if (v<l || v>r) return 0;
    return 1;
}
int findpath(int l,int r)
{
    deque<ii> q;
    if (!inpath(a[1][1],l,r)) return 0;
    q.pb(mp(1,1));
    while (q.size())
    {
        ii t=q.back();
        q.pop_back();
        for (int k=0;k<4;k++)
        {
            int u=t.X+x[k];
            int v=t.Y+y[k];
            if (!inpath(a[u][v],l,r)) continue;
            if (ck[u][v]==num) continue;
            ck[u][v]=num;
            if (u==n && v==n) return 1;
            q.push_front(mp(u,v));
        }
    }
    return 0;
}

int check(int lech)
{
    for (int i=1;i+lech<=111;i++)
    {
        num++;
        if (findpath(i,i+lech)) return 1;
    }
    return 0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            a[i][j]++;
        }

    int l=0,r=110;
    while (r-l>1)
    {
        int mid=(r+l)>>1;
        if (check(mid)) r=mid;
        else l=mid;
    }
    if (check(l)) cout<<l;
    else cout<<r;
}
