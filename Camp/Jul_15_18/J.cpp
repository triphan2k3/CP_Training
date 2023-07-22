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

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector<ld> p(n + 1, 0);
    FOR(i, 1, n) cin >> p[i];
    vector<vector<pair<ld, ld>>> dp(n + 1, vector<pair<ld, ld>> (n + 1, {0, 1}));
    ld ans = 0;
    FOR(i, 1, n) {
        FOR(j, 1, i) { // maxprob when choice j out off i
            dp[i][j] = dp[i - 1][j];
            ld f = dp[i - 1][j - 1].F * (1 - p[i]) + dp[i - 1][j - 1].S * p[i];
            ld s = dp[i - 1][j - 1].S * (1 - p[i]);
            dp[i][j] = max(dp[i][j], {f, s});
            ans = max(ans, dp[i][j].F);
        }
    }
    cout << setprecision(9) << fixed << ans;
}