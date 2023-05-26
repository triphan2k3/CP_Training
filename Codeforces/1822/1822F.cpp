#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int h[N], d[N];
int dp[N];

void dfs(int u, int p) {
    for (int v:a[u]) if (v != p) {
        h[v] = h[u] + 1;
        dfs(v, u);
    }
    d[u] = h[u];
    for (int v:a[u])
        if (v != p)
            d[u] = max(d[u], d[v]);
}

void dfs2(int u, int p, int inherit = 0) {
    vector<int> pre(a[u].size()), suf(a[u].size());
    
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (v == p) {
            pre[i] = (i == 0) ? 0 : pre[i - 1];
        } else 
            pre[i] = (i == 0) ? d[v] - h[u] : max(pre[i - 1], d[v] - h[u]);
    }

    for (int i = a[u].size() - 1; i >= 0; i--) {
        int v = a[u][i];
        if (v == p)
            suf[i] = (v == a[u].back()) ? 0 : suf[i + 1];
        else 
            suf[i] = (v == a[u].back()) ? d[v] - h[u] : max(suf[i + 1], d[v] - h[u]);
    }

    dp[u] = max(inherit, max(suf[0], pre[a[u].size() - 1])); // void p is a[u][0]
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (v == p) continue;
        int nextinherit = inherit;
        if (i != 0)
            nextinherit = max(nextinherit, pre[i - 1]);
        if (i + 1 != a[u].size())
            nextinherit = max(nextinherit, suf[i + 1]);
        dfs2(v, u, nextinherit + 1);
    }
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k, c;
        cin >> n >> k >> c;
        FOR(i, 1, n) {
            a[i].clear();
            //d[i] = 0;//h[i] = 0;//dp[i] = 0;
        }
        FOr(i, 1, n) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1, 0);
        dfs2(1, 0);
        // FOR(i, 1, n) {
        //     cout << dp[i] << " ";
        // } cout << "\n";
        ll ans = 1LL * dp[1] * k;
        FOR(i, 2, n)
            ans = max(ans, 1LL * dp[i] * k - 1LL * (h[i] - h[1]) * c);
        std::cout << ans << "\n";
    }
}