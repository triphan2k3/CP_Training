#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1337C.INP"
#define out "1337C.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,k;
int h[N],sz[N],ans[N];
vector<int> a[N];
//vector<ii> ans;
void dfs(int u,int p)
{
    for (int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if (v==p) continue;
        h[v]=h[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    sz[u]++;
    //ans.push_back({h[u],u});
}
bool cmp(int u,int v) //ii a,ii b)
{
    return h[u]-sz[u]>h[v]-sz[v];
    //return a.X-sz[a.Y] > b.X-sz[b.Y];
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>k;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for (int i=1;i<=n;i++)
        ans[i]=i;
    dfs(1,0);
    //sort(ans.begin(),ans.end(),cmp);
    sort(ans+1,ans+n+1,cmp);
    ll res=0;
    for (int i=1;i<=k;i++)
        res=res+(ll)(h[ans[i]]-sz[ans[i]]+1);
    cout<<res;
}
