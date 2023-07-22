#include <bits/stdc++.h>
#define TASK "1354E"
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

const int N=(int)5e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> e[N],tp[N];
vector<ii> p;
int dp[N][N];
int sz[N][2];
int visit[N],ans[N],f[N];
int m,n,a,b,c,ck,q;

void dfs(int u,int k) {
    sz[u][k]=1;
    for(int v:e[u]) {
        if (!visit[v]) {
            visit[v]=visit[u]+1;
            dfs(v,k^1);
            sz[u][0]+=sz[v][0];
            sz[u][1]+=sz[v][1];
        } else
        if ((visit[v]-visit[u]) % 2 == 0) ck=1;
    }
    tp[q].pb(u);
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> a >> b >> c;
    FOR(i, 1, m) {
        int u,v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    int sum=0;
    p.push_back({0,0});
    FOR(i, 1, n)
        if (!visit[i]) {
            visit[i]=1;
            ++q;
            dfs(i,0);
            p.push_back({sz[i][0],sz[i][1]});
        }
    if (ck==1) {
        cout << "NO";
        return 0;
    }
    dp[0][0]=1;
    FOr(i,1,p.size())
        FOR(j,min(p[i].F,p[i].S),b) {
            if (j>=p[i].F)
                dp[i][j]|=dp[i-1][j-p[i].F];
            if (j>=p[i].S)
                dp[i][j]|=dp[i-1][j-p[i].S];
        }
    if (!dp[p.size()-1][b]) {
        cout << "NO";
        return 0;
    }
    FOD(i,p.size()-1,1) {
        if (b>=p[i].F && dp[i-1][b-p[i].F]) {
            b-=p[i].F;
            f[i]=1;
        } else
            b-=p[i].S;
    }
    FOR(i,1,q)
        for(int u:tp[i]) {
            if (visit[u]%2 == f[i])
                ans[u]=2;
            else
                if (a)
                    ans[u]=1,--a;
                else
                    ans[u]=3,--b;
        }
    cout << "YES\n";
    FOR(i,1,n)
        cout << ans[i];
}
