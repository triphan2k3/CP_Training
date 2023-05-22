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
vector<ii> a[N];
vector<int> ans;
int rem[N];

iii ciii(int a, int b, int c) {
    return {{a, b}, c};
}

bool dfs(int u, int p) {
    int ret = true;
    vector<int> r;
    for (ii item:a[u]) 
        if (item.first != p) {
            int v = item.first;
            if (dfs(v, u) == false)
                return false;
            if (rem[v] == 3) {
                ans.push_back(item.second);
                rem[v] = 0;
            }
            if (rem[v])
                r.pb(rem[v]);
        }
    if (r.size() == 0) {
        rem[u] = 1;
        return (u != 1);
    }
    sort(r.begin(), r.end());
    if (r.size() > 2 || (r.size() == 2 && r[0] + r.back() > 2))
        return false;
    if (r.size() == 2)
        rem[u] = 3;
    else 
        rem[u] = 1 + r[0];
    if (u == 1)
        return rem[u] == 3;
    return true;
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
        FOR(i, 1, n) a[i].clear();
        FOr(i, 1, n) {
            int u, v;
            cin >> u >> v;
            a[u].push_back({v, i});
            a[v].push_back({u, i});
        }
        if (n % 3 == 0 && dfs(1, 0)) {
            cout << ans.size() << "\n";
            for(int x:ans)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
        ans.clear();
    }
}