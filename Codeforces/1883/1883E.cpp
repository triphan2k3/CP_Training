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

vector<int> e[N];
vector<int> temp;
int vis[N], cnt[N];

void dfs(int u) {
    vis[u] = 1;
    temp.push_back(u);
    int deg = e[u].size();
    for (int v:e[u])
        if (!vis[v])
            dfs(v);
    return;
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
    while (t--) {
        int n;
        cin >> n;
        FOR(i, 1, n) {
            e[i].clear();
            vis[i] = 0;
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int j; cin >> j;
            cnt[j]++;
            e[i].push_back(j);
            e[j].push_back(i);
        }
        int mi = 0, ma = 0;
        FOR(i, 1, n) if (!vis[i]) {
            temp.clear();
            ++ma;
            dfs(i);
            for(int u:temp)
                if (cnt[u] != 1 || temp.size() == 2) {
                    mi++;
                    break;
                }
        }
        if (mi == 0)
            mi = ma;
        else 
            mi = ma - mi + 1;
        // mi = max(mi + 1, ma);
        cout << mi << " " << ma << "\n";
    }
}