#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a[N];
int dp[N];
void dfs(int u, int p = 0, int id = 0) {
    dp[u] = 0;
    for (ii e:a[u]) {
        int v = e.F;
        int nid = e.S;
        if (v == p) continue;
        dfs(v, u, nid);
        if (nid < id)
            dp[u] = max(dp[u], dp[v] + 1);
        else 
            dp[u] = max(dp[u], dp[v]);
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
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i, 1, n) {
            a[i].clear();
            dp[i] = 0;
        }
        FOr(i, 1, n) {
            int u, v;
            cin >> u >> v;
            a[u].pb({v, i});
            a[v].pb({u, i});
        }
        dfs(1, 0);
        cout << dp[1] + 1 << "\n";
    }
}