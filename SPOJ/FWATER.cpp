#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "FWATER.INP"
#define out "FWATER.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N];
int d[N],ck[N];
int n;
int findmst()
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,0));
    for (int i=1;i<=n;i++)
        d[i]=MOD;
    int ans=0;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        int w=t.X;
        int u=t.Y;
        if (w!=d[u]) continue;
        ck[u]=1;
        ans+=w;
        for (int v=1;v<=n;v++)
            if (a[u][v]<d[v] && ck[v]==0)
            {
                d[v]=a[u][v];
                q.push(mp(d[v],v));
            }
    }
    return ans;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        a[0][i]=a[i][0];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];

    cout<<findmst();
}
