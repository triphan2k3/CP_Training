#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "FFLOW.INP"
#define out "FFLOW.OUT"
using namespace std;
const int N=(int)3e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
iii e[N];
vector<int> a[N];
int trace[N],visit[N],use[N],last[N];
int n,m,T,s,t;
ll flow;
ll MINF;
void adddedge(int i,int u,int v,int w)
{
    a[u].push_back(2*i  );
    a[v].push_back(2*i+1);
    e[2*i]  ={{u,v},w};
    e[2*i+1]={{v,u},0};
}
void addedge(int i,int u,int v,int w)
{
    a[u].push_back(4*i  );
    a[v].push_back(4*i+1);
    a[v].push_back(4*i+2);
    a[u].push_back(4*i+3);
    e[4*i]  ={{u,v},w};
    e[4*i+1]={{v,u},0};
    e[4*i+2]={{v,u},w};
    e[4*i+3]={{u,v},0};
    return;
}
bool findpath()
{
    for (int i=1;i<=n;i++)
        trace[i]=-1;
    trace[s]=0;
        //trace[1]=10000000;
    deque<int> q;
    q.push_front(s);
    while (q.size())
    {
        int u=q.back();
        q.pop_back();
        for (int j=0;j<a[u].size();j++)
        {
            int i=a[u][j];
            int v=e[i].X.Y;
            int w=e[i].Y;
            if (trace[v]!=-1 || w==0) continue;
            trace[v]=trace[u]+1;
            q.push_front(v);
        }
    }
    return trace[t]!=-1;
}
int upflow(int u,int F)
{
    if (u==t) return F;
    //visit[u]=T;
    int sumflow=0;
    for (int j=0;j<a[u].size();j++)
    {
        last[u]=j;
        int i=a[u][j];
        int v=e[i].X.Y;
        int w=e[i].Y;
        if (w<MINF) continue;
        if (trace[v]!=trace[u]+1) continue;
        //if (visit[v]==T) continue;
        if (w==0) continue;
        int x=upflow(v,min(F,w));
        if (x==0) continue;
        e[i].Y-=x;
        e[i^1].Y+=x;
        return x;
    }
    return 0;
    return sumflow;
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;//>>s>>t;//>>s>>t;
    s=1;
    t=n;
    //int cnt=-1;
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        //if (u==v) continue;
        addedge(i,u,v,w);
    }
    //m=cnt;
    MINF=1000000000;
    while (findpath())
    {
        for (int i=1;i<=n;i++)
            last[i]=0;
        flow+=(ll)upflow(s,1000000000);
        MINF/=2;
    }
    cout<<flow<<"\n";
    return 0;

    for (int u=1;u<=n;u++)
        if (trace[u])
        for (int j=0;j<a[u].size();j++)
    {
        int i=a[u][j];
        int v=e[i].X.Y;
        if (!trace[v])
            use[i/4]=1;
    }
    for (int i=1;i<=m;i++)
        if (use[i])
            cout<<i+1<<" ";
}
