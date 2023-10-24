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

ll dp[1000][1000];

ll fpow(int a, int b) {
    if (b == 0)
        return 1;
    ll tmp = fpow(a, b / 2);
    tmp = tmp * tmp % MOD;
    if (b % 2)
        tmp = tmp * a % MOD;
    return tmp;
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int &x:s) cin >> x;
    s.push_back(m + 1);
    FOR(i, 1, m + 1)
        dp[i][m + 1] = m + 1 - i;
    
    ll half = fpow(2, MOD - 2);
    FOD(j, m, 1)
        FOD(i, j - 1, 1) {
            dp[i][j] = (half * (dp[i + 1][j] + 1) + half * dp[i][j + 1]) % MOD;
        }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[s[i - 1]][s[i]];
    cout << ans % MOD;
}