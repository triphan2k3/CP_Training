#include <bits/stdc++.h>
#define TASK "1345E"
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
int m,n;
int in[N],out[N],ans[N];
int dp[2][N],ok[2][N];
ii p[N];
vector<int> e[2][N];

bool check(int u) {
    in[u]=1;
    int kt=1;
    for (int v:e[0][u]) {
        if (!in[v])
            kt=check(v);
        else
            if (!out[v]) kt=0;
        if (kt==0) return 0;
    }
    out[u]=1;
    return 1;
}
int dfs(int i,int u) {
    ok[i][u]=1;
    dp[i][u]=u;
    for (int v:e[i][u]) {
        if (dp[i][v])
            dp[i][u]=min(dp[i][u],dp[i][v]);
        else
            dp[i][u]=min(dp[i][u],dfs(i,v));
    }
    return dp[i][u];
}

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1,u,v;i<=m;i++) {
        cin >> u >> v;
        p[i]={u,v};
        e[0][u].push_back(v);
        e[1][v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        e[0][0].push_back(i);
        e[1][0].push_back(i);
    }
    if (!check(0)) {
        cout << -1;
        return 0;
    }

    dfs(0,0);
    dfs(1,0);
    for (int i=1;i<=m;i++) {
        int u=p[i].F;
        int v=p[i].S;
        ans[max(u,v)]=1;
        if (u<v) {
            if (dp[0][v]<u) ans[u]=1;
        }
        else {
            if (dp[1][u]<v) ans[v]=1;
        }
    }

    int res=n;
    for (int i=1;i<=n;i++)
        res-=ans[i];
    cout<<res<<"\n";
    for (int i=1;i<=n;i++)
        if (ans[i])
            cout<<"E";
        else
            cout<<"A";

}
