#include <bits/stdc++.h>
#define TASK "219D"
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

const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

vector<int> e[N],g[N];
int f[N],h[N];
int n,cnt;
void dfs(int u,int p=0) {
    for(int v: g[u])
        if (v!=p) {
            cnt++;
            f[v]=f[u]+1;
            h[v]=h[u]+1;
            dfs(v,u);
    }
    for (int v:e[u])
        if (v!=p) {
            f[v]=f[u];
            h[v]=h[u]+1;
            dfs(v,u);
        }
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
        e[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int ans=n-1;
    FOR(i,1,n)
        ans=min(ans,cnt+h[i]-2*f[i]);
    vector<int> p;
    FOR(i,1,n)
        if (cnt+h[i]-2*f[i] == ans)
            p.push_back(i);
    cout << ans << "\n";
    for (int i:p)
        cout << i << " ";
}
