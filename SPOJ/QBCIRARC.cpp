#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBCIRARC.INP"
#define out "QBCIRARC.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> e;
vector<ii> a,res;
int m,n,last,dau;
int T;
int ck[N],gcc[N];
int par[N];

int dfs(int u,int x,int y)
{
    ck[u]=T;
    for (int v:e[u])
    {
        if (u==x && v==y) continue;
        if (gcc[v]==T) continue;
        if (ck[v]==T)
        {
            last=u;
            dau=v;
            return 1;
        }
        par[v]=u;
        if (dfs(v,x,y)) return 1;
    }
    gcc[u]=T;
    return 0;
}
int check(int u,int v)
{
    T++;
    for (int i=1;i<=n;i++)
        if (ck[i]!=T)
            if (dfs(i,u,v)) return 0;
    return 1;
}
bool tttd(int x,int y)
{
    string s1="",s2="";
    while (x)
    {
        s1=(char)(x%10+48)+s1;
        x/=10;
    }
    while (y)
    {
        s2=(char)(y%10+48)+s2;
        y/=10;
    }
    return s1<s2;
}
bool cmp(ii x,ii y)
{
    //while (x.X*10<=y.X) x.X*=10;
    //while (y.X*10<=x.X) y.X*=10;
    if (x.X!=y.X) return tttd(x.X,y.X);
    //while (x.Y*10<=y.Y) x.Y*=10;
    //while (y.Y*10<=x.Y) y.Y*=10;
    //if (x.Y!=y.Y)
    return tttd(x.Y,y.Y);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    e.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        e[u].push_back(v);
    }
    T++;
    for (int i=1;i<=n;i++)
        if (!ck[i])
            if (dfs(i,0,0)) break;

    int temp=last;
    if (last==0)
    {
        cout<<"-1";
        return 0;
    }
    a.push_back(make_pair(last,dau));
    while (last!=dau)
    {
        a.push_back(make_pair(par[last],last));
        last=par[last];
    }

    for (ii x:a)
        if (check(x.X,x.Y)) res.pb(mp(x.X,x.Y));

    if (res.size()==0)
    {
        cout<<"-1";
        return 0;
    }
    sort(res.begin(),res.end(),cmp);
    cout<<res.size()<<"\n";
    for (int i=0;i<res.size();i++)
        cout<<res[i].X<<" "<<res[i].Y<<"\n";
}
