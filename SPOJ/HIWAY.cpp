#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "HIWAY.INP"
#define out "HIWAY.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct edge
{
    int U,V,W,C;
} e[N];
int trace[N],d[N],inq[N],path[2][N];
vector<int> ans[2];
vector<int> a[N];
int m,n,s,t,mincost,flow;

void addedge(int i, int u, int v, int w)
{
    e[4*i]  ={u,v, w,1};
    e[4*i+1]={v,u,-w,0};
    e[4*i+2]={v,u, w,1};
    e[4*i+3]={u,v,-w,0};
    a[u].pb(4*i)  ; a[u].pb(4*i+3);
    a[v].pb(4*i+1); a[v].pb(4*i+2);
    return;
}
bool bellmanford()
{
    for (int i=1;i<=n;i++)
        d[i]=MOD;
    d[s]=0;
    deque<int> q;
    q.pb(s);
    while (q.size())
    {
        int u=q.back(); q.pop_back();
        inq[u]=0;
        for (int i:a[u])
        {
            int v=e[i].V;
            int c=e[i].C;
            int w=e[i].W;
            if (c)
            if (d[u]+w<d[v])
            {
                trace[v]=i;
                d[v]=d[u]+w;
                if (!inq[v])
                    q.push_front(v);
                inq[v]=1;
            }
        }
    }
    return d[n]!=MOD;
}
void upflow()
{
    int v=n;
    while (v!=s)
    {
        int i=trace[v];
        int u=e[i].U;
        e[i].C-=1;
        e[i^1].C+=1;
        v=u;
    }
    mincost+=d[n];

    for (int i=1;i<=n;i++)
        path[flow][i]=trace[i];
    flow++;
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addedge(i,u,v,w);
    }
    n++;
    e[4*(m+1)]={t,n,0,2};
    a[t].push_back(4*(m+1));
    while (bellmanford())
        upflow();
    int v=t;
    for (int i=0;i<=1;i++)
    for (int v=t;v!=s;v=e[path[i][v]].U)
        ans[i].push_back(v);

    ans[0].pb(1);
    ans[1].pb(1);
    reverse(ans[0].begin(),ans[0].end());
    reverse(ans[1].begin(),ans[1].end());
    for (int i=1;i<=n;i++)
        d[i]=0;
    for (int i=0;i<ans[1].size();i++)
        d[ans[1][i]]=i;
    d[s]=d[t]=0;
    int last1=ans[0].size(),last2=ans[1].size(),firs1=ans[0].size(),firs2=ans[1].size();
    for (int i=0;i<ans[0].size();i++)
        if (d[ans[0][i]])
        {
            last1=i-1;
            firs2=d[ans[0][i]];
            break;
        }
    for (int i=1;i<=n;i++)
        d[i]=0;
    for (int i=0;i<ans[0].size();i++)
        d[ans[0][i]]=i;
    d[s]=d[t]=0;
    for (int i=0;i<ans[1].size();i++)
        if (d[ans[1][i]])
        {
            last2=i-1;
            firs1=d[ans[1][i]];
            break;
        }
    cout<<mincost<<"\n";
    cout<<last1+ans[1].size()-firs2;
    for (int i=0;i<last1;i++)
        cout<<" "<<ans[0][i];
    for (int i=firs2;i<ans[1].size();i++)
        cout<<" "<<ans[1][i];
    cout<<"\n";

    cout<<last2+ans[0].size()-firs1;
    for (int i=0;i<last2;i++)
        cout<<" "<<ans[1][i];
    for (int i=firs1;i<ans[0].size();i++)
        cout<<" "<<ans[0][i];
}
