#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "ADS.INP"
#define out "ADS.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

vector<vector<int>> a;
int ok[N];
void dfs(int u)
{
    ok[u]=1;
    for (int v:a[u])
        if (!ok[v]) dfs(v);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int n,m;
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (!ok[i]) dfs(i),cnt++;
    cout<<m-n+cnt;

}
