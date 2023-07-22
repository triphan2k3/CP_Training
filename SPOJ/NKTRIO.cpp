#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKTRIO.INP"
#define out "NKTRIO.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> e;
int par[N];
int a[N][N];
int ck[N],gcc[N];
int n,T;
void solve(int dau,int cuoi)
{
    while (1)
    {
        int giua=par[dau];
        if (a[par[giua]][dau])
        {
            cout<<dau<<" "<<giua<<" "<<par[giua];
            return;
        }
        par[dau]=par[giua];
    }
}
int findpath(int u)
{
    ck[u]=1;
    for (int v:e[u])
    {
        if (gcc[v]) continue;
        if (ck[v])
        {
            solve(u,v);
            return 1;
        }
        par[v]=u;
        if (findpath(v)) return 1;
    }
    gcc[u]=1;
    return 0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    e.resize(n+1);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        cin>>a[i][j];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (!a[i][j] && i!=j) e[i].pb(j);

    for (int i=1;i<=n;i++)
        if (!ck[i])
        {
            ck[i]=1;
            if (findpath(i)) return 0;
        }
    cout<<"-1 -1 -1";
}


