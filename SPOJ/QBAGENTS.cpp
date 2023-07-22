#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBAGENTS.INP"
#define out "QBAGENTS.OUT"
using namespace std;
struct iii
{
    int st,nd,rd;
};
const int N=255;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[N][N][2];
int n,m,s,t;
vector<vector<int>> e;

iii make(int a,int b,int c)
{
    iii t;
    t.st=a;
    t.nd=b;
    t.rd=c;
    return t;
}
int bfs()
{
    if (s==t) return 0;
    f[s][t][0]=1;
    deque<iii> q;
    q.pb(make(s,t,0));
    while (q.size())
    {
        iii temp=q.back();
        q.pop_back();
        int u=temp.st;
        int v=temp.nd;
        int sta=temp.rd;
        if (sta==0 && u==v) return f[u][v][sta]-1;
        if (sta==0)
        for (int nx:e[u])
            if (!f[nx][v][1])
            {
                f[nx][v][1]=f[u][v][0]+1;
                q.push_front(make(nx,v,1));
            }

        if (sta==1)
        for (int nx:e[v])
            if (!f[u][nx][0])
            {
                f[u][nx][0]=f[u][v][1];
                q.push_front(make(u,nx,0));
            }
    }
    return -1;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>s>>t;
    e.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        e[u].pb(v);
    }
    cout<<bfs();
}
