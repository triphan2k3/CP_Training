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
const int MOD=998244353;
const ll INF=(ll)1e18+7;

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x:a) cin >> x;
    for (int &x:b) cin >> x;
    int m; cin >> m;
    vector<int> c(m), d(m);
    for (int &x:c) cin >> x;
    for (int &x:d) cin >> x;

    map<int, int> xdivy;
    FOr(i, 0, n)
        xdivy[a[i]] += b[i];
    FOr(i, 0, m)
        xdivy[c[i]] -= d[i];
    for (auto it = xdivy.begin(); it != xdivy.end(); it++)
        if (it->second < 0) {
            cout << 0;
            return 0;
        }
    ll ans = 1;
    for (auto it = xdivy.begin(); it != xdivy.end(); it++) {
        if (it->second == 0) continue;
        ans *= 2;
        ans %= MOD;
    }
    cout << ans;
}