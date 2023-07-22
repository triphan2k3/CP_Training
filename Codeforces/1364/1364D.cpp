#include <bits/stdc++.h>
#define TASK "1364D"
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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n, m, k, p[N], d[N];
vector<int> a[N];

void dfs(int u) {
    for (int v:a[u]) if (p[v] == 0) {
        d[v] = d[u] + 1;
        p[v] = u;
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    p[1]=-1;
    dfs(1);
    bool cyc = 0;
    int mnlen = 1e9, mnu, mnv;
    FOR(u,2,n)
    {
        for (int v:a[u])
        if (v != p[u] && d[v] < d[u]) {
            int len=d[u]-d[v]+1;
            cyc = 1;
            if (len < mnlen)
            {
                mnlen = len;
                mnu = u;
                mnv = v;
            }
            if (len <= k)
            {
                int vv = u;
                cout << "2\n" << len << '\n';
                while (vv != v)
                {
                    cout << vv << ' ';
                    vv = p[vv];
                }
                cout << v;
                return 0;
            }
        }
    }
    if (!cyc)
    {
        int odd = 0, mo = 1;
        FOR(i, 1, n) if (d[i] & 1) odd++;
        cout << "1\n";
        if (odd < n - odd) mo = 0;
        int cnt = 0;
        FOR(i, 1, n)
        {
            if (d[i] % 2 == mo)
            {
                cnt++;
                cout << i << ' ';
            }
            if (cnt == (k + 1) / 2) break;
        }
    } else
    {
        vector<int> ans;
        int vv = mnu;
        cout << "1\n";
        while (vv != mnv)
        {
            ans.pb(vv);
            vv = p[vv];
        }
        ans.pb(mnv);
        k = (k + 1) / 2;
        FOR(i, 0, k - 1) cout << ans[i * 2] << ' ';
    }
    return 0;
}
