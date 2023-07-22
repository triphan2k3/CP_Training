#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PBCPOINT.INP"
#define out "PBCPOINT.OUT"
using namespace std;
const int N=1000;
const int MAX=2*N+5;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[MAX][MAX],row[MAX][MAX],col[MAX][MAX];
int lef[MAX],rig[MAX],up[MAX],dw[MAX];
int res;
int n;
deque<ii> q;

int next_col(int x,int y)
{
    int t=col[x][y];
    if (y==1002)
        int z=0;
    if (a[x][t]==0) return t;
    return col[x][y]=next_col(x,t);
}
int next_row(int x,int y)
{
    int t=row[x][y];
    if (a[t][y]==0) return t;
    return row[x][y]=next_row(t,y);
}
void getlr(int i,int j)
{
    lef[i]=min(lef[i],j);
    rig[i]=max(rig[i],j);
}
void getupdw(int i,int j)
{
    up[j]=max(up[j],i);
    dw[j]=min(dw[j],i);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<=2*N;i++)
        for (int j=0;j<=2*N;j++)
            {
                row[i][j]=i+1;
                col[i][j]=j+1;
            }
    for (int i=0;i<=2*N;i++)
        lef[i]=dw[i]=2*N+1;
    for (int i=0;i<=2*N;i++)
        rig[i]=up[i]=-1;
    for (int i=1,u,v;i<=n;i++)
    {
        cin>>u>>v;
        u+=N;
        v+=N;
        if (a[u][v]) continue;
        res++;
        q.pb(mp(u,v));
        a[u][v]=1;
        lef[u]=min(lef[u],v);
        rig[u]=max(rig[u],v);
        up[v]=max(up[v],u);
        dw[v]=min(dw[v],u);
    }

    while (q.size())
    {
        int i=q.back().X;
        int j=q.back().Y;
        q.pop_back();
        for (int x=lef[i];x<=rig[i];)
        {
            x=next_col(i,x);
            if (x>rig[i]) break;
            res++;
            getupdw(i,x);
            a[i][x]=1;
            q.push_front(mp(i,x));
        }
        for (int y=dw[j];y<=up[j];)
        {
            y=next_row(y,j);
            if (y>up[j]) break;
            res++;
            getlr(y,j);
            a[y][j]=1;
            q.push_front(mp(y,j));
        }
    }
    cout<<res;
}
