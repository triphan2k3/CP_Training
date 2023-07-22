#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "HAOI6000.INP"
#define ou "HAOI6000.OUT"
using namespace std;
struct iii
{
    int st,nd,rd;
};
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N];
int f[N][N][2];
int m,n,stt,res,t;
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};

bool out(int i,int j)
{
    return i==0 || j==0 || i==m+1 || j==n+1;
}
iii make(int a,int b,int c)
{
    iii t;
    t.st=a;
    t.nd=b;
    t.rd=c;
    return t;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(ou,"w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    deque<iii> q;
    for (int i=1;i<=n;i++)
    {
        q.pb(make(1,i,0));
        f[1][i][0]=1;
    }
    while (q.size())
    {
        iii tp=q.back();
        q.pop_back();
        int i=tp.st;
        int j=tp.nd;
        int sta=tp.rd;
        if (i==m && sta==1 && res==0)
            res=f[i][j][1];
        for (int k=0;k<4;k++)
            {
                int u=i+x[k];
                int v=j+y[k];
                if (out(u,v)) continue;
                if (i+1==u)
                {
                    if (sta==0 || f[u][v][0]) continue;
                    f[u][v][0]=f[i][j][1]+1;
                    q.push_front(make(u,v,0));
                }
                if (i-1==u)
                {
                    if (sta==1 || f[u][v][1]) continue;
                    f[u][v][1]=f[i][j][0]+1;
                    q.push_front(make(u,v,1));
                }
                if (j+1==v)
                {
                    if (a[i][j]!=sta) continue;
                    stt=1-a[u][v];
                    if (f[u][v][stt]) continue;
                    f[u][v][stt]=f[i][j][sta]+1;
                    q.push_front(make(u,v,stt));
                }
                if (j-1==v)
                {
                    if (a[i][j]==sta) continue;
                    stt=a[u][v];
                    if (f[u][v][stt]) continue;
                    f[u][v][stt]=f[i][j][sta]+1;
                    q.push_front(make(u,v,stt));
                }

            }
    }
    if (res==0)
    {
        cout<<"0 0";
        return 0;
    }

    for (int i=1;i<=n;i++)
        if (f[m][i][1]==res) t++;
    cout<<res<<" "<<t;

}
