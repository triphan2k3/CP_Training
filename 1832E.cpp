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
    int n, x, y, m, k; cin >> n;
    vector<int> a(n);
    cin >> a[0];
    cin >> x >> y >> m >> k;
    FOR(i, 1, n - 1)
        a[i] = (a[i - 1] * 1LL * x + y) % m;

    FOR(i, 1, n - 1) {
        a[i] = (a[i] + a[i - 1]) % MOD;
    }

    vector<vector<int>> dp(7, vector<int> (n + 1, 0));
    FOr(i, 0, n)
        dp[0][i + 1] = a[i];
        
    FOR(i, 1, n)
        dp[1][i] = (dp[1][i - 1] + dp[0][i]) % MOD;

    FOR(j, 2, k)
    FOR(i, 1, n) {
        dp[j][i] = (dp[j][i - 1] + dp[j - 1][i - 1]) % MOD;
    }

    ll ans = 0;
    FOR(i, 1, n) {
        ans ^= dp[k][i] * 1LL * i;
    }
    cout << ans;
}