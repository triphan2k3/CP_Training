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
vector<int> a[N];
int sz[N];
double expected[N];
int n;

void dfs(int u) {
    sz[u] = 1;
    for (int v:a[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    return;
}

void dp(int u) {
    for (int v:a[u]) {
        expected[v] = expected[u] + (sz[u] - sz[v] - 1) / 2.0 + 1;
        dp(v);
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
    cin >> n;
    FOR(v, 2, n) {
        int u; cin >> u;
        a[u].push_back(v);
    }
    dfs(1);
    expected[1] = 1;
    dp(1);
    for (int i = 1; i <= n; i++)
        cout << setprecision(6) << fixed << expected[i] << " ";
}