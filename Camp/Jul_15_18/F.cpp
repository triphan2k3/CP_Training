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

long double pw(long double a, int b) {
    if (abs(a) < 1e-9)
        return 0;
    if (b == 0)
        return 1;
    ld t = pw(a, b / 2);
    t *= t;
    if (b % 2)
        t *= a;
    return t;
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int m, n;
    cin >> m >> n;
    ld p[2] = {0, 1};
    ld ans = 0;
    FOR(i, 2, m + 1) {
        // cal P(ans >= i)
        // P(ans = i - 1) = P(ans >= i - 1) - P(ans >= i)
        // P(ans = 2) = P(ans >= 1) - P(ans >= 2)

        // P(ans >= i)
        p[i % 2] = 1 - pw(1.0 * (i - 1) / m, n);
        ans += (p[(i + 1) % 2] - p[i % 2]) * (i - 1);
    }
    cout << setprecision(4) << fixed << ans;
}