#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "ONBRIDGE.INP"
#define out "ONBRIDGE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int side[N],par[N],_dsu[N],dsu[N],visit[N];
int m,n,bridge,numlca;

/*
dsu[] la chi so dai dien trong thang phan lien thong
_dsu[] la chi so dai dien trong chu tring don
visit[] la danh dau tim lca
par[] la dinh cha
side[] la so luong nut ma tplt quan li
*/
int _head(int u) // nhan chi so dai dien, -1 de ket hop vs ctrcon sau
{
    if (u==-1) return -1;
    return _dsu[u]==u ? u : _dsu[u]=_head(_dsu[u]);
}
int head(int u) //dsu bth
{
    u=_head(u);
    return dsu[u]==u ? u : dsu[u]=head(dsu[u]);
}

void setroot(int u) // cho u thanh dinh cha trong tplt
{
    u=_head(u);
    int child=-1;
    int root=u; //vi du ta co cau truc cay 1-2 1-3 3-4 root la 1 thi de cho 3 thanh root thi chi can set par lai dinh 2
    while (u!=-1)
    {
        int p=_head(par[u]);
        par[u]=child;

        dsu[u]=root; //luc nay dinh u coi nhu thay bang dinh root

        child=u;
        u=p;
    }
    side[root]=side[child]; // ke thua nut cha trc do
}

void merge_path(int u,int v)
{
    numlca++;
    vector<int> path_u,path_v;
    int lca=-1;
    int cu=_head(u),cv=_head(v);
    while (lca == -1)
    {
        if (u!=-1)
        {
            u=_head(u);
            path_u.push_back(u);
            if (visit[u]==numlca)
                lca=u;
            visit[u]=numlca;
            u=par[u];
        }
        if (v!=-1)
        {
            v=_head(v);
            path_v.push_back(v);
            if (visit[v]==numlca)
                lca=v;
            visit[v]=numlca;
            v=par[v];
        }

    }
    for (int x:path_u)
    {
        _dsu[x]=lca;
        if (x==lca) break;
        bridge--;
    }
    for (int x:path_v)
    {
        _dsu[x]=lca;
        if (x==lca) break;
        bridge--;
    }
}
void add_edge(int u,int v)
{
    u=_head(u);
    v=_head(v);
    if (u==v) return;
    int cu=head(u);
    int cv=head(v);
    if (cu!=cv)
    {
        bridge++;
        if (side[v]>side[u])
        {
            swap(u,v);
            swap(cu,cv);
        }
        setroot(v);
        par[v]=dsu[v]=u;
        side[u]+=side[v];
    } else merge_path(u,v);

}
void setup()
{
    for (int i=0;i<n;i++)
        dsu[i]=_dsu[i]=i;
    for (int i=0;i<n;i++)
        par[i]=-1;
    for (int i=0;i<n;i++)
        side[i]=visit[i]=0;
    bridge=numlca=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        int u,v;
        setup();
        for (int i=1;i<=m;i++)
        {
            cin>>u>>v;
            add_edge(u,v);
            cout<<bridge<<"\n";
        }
    }
}
