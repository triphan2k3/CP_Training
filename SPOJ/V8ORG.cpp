#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "V8ORG.INP"
#define out "V8ORG.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int chil[N];
int n,k,cnt;
vector<vector<int>> a;

void dfs(int u)
{
    chil[u]=1;
    for (int v:a[u])
    {
        dfs(v);
        chil[u]+=chil[v];
    }
    if (chil[u]>=k)
    {
        cnt++;
        chil[u]=0;
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>k;
    cin>>n;
    a.resize(n+1);
    for (int i=2,u;i<=n;i++)
    {
        cin>>u;
        a[u].pb(i);
    }
    dfs(1);
    cout<<cnt;
}
