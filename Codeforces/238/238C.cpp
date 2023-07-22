#include <bits/stdc++.h>
#define TASK "238C"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)3e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> e[N],a[N];
int f[N],g[N];
int n;

void dfs(int u,int p) {
    for (int v:e[u]) if (v!=p) {
        dfs(v,u);
        f[u]+=f[v];
    }
    for (int v:a[u]) if (v!=p) {
        dfs(v,u);
        f[u]+=f[v]+1;
    }
    g[u]=f[u];
    for (int v:e[u])
        if (v!=p)
            g[u]=min(g[u],f[u]-f[v]+g[v]+1);
    for (int v:a[u])
        if (v!=p)
            g[u]=min(g[u],f[u]-f[v]+g[v]-1);
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,2,n) {
        int u,v;
        cin >> u >> v;
        e[u].pb(v);
        a[v].pb(u);
    }
    int ans=n-1;
    FOR(u,1,n) {
        FOR(i,1,n)
            f[i]=g[i]=0;
        dfs(u,0);
        FOR(v,1,n)
            ans=min(ans,f[u]-f[v]+g[v]);
    }
    cout << ans;
}
