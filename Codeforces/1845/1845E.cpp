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

const int N=2007;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int dp[2][121][N];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x:a) cin >> x;

    dp[0][60][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 120; j++)
        for (int t = 0; t <= k; t++)
            dp[i % 2][j][t] = 0;

        for (int j = 0; j <= 120; j++)
            for (int t = 0; t <= k; t++) if (dp[(i + 1) % 2][j][t]) {
                // let 1 ball to i
                int nj = j + 1 - a[i - 1];
                int nt = t + abs(nj - 60);
                if (nt <= k)
                    (dp[i % 2][nj][nt] += dp[(i + 1) % 2][j][t]) %= MOD;
                nj = j - a[i - 1];
                nt = t + abs(nj - 60);
                if (nt <= k)
                    (dp[i % 2][nj][nt] += dp[(i + 1) % 2][j][t]) %= MOD;
            }
    }
    int ans = 0;
    for (int t = k & 1; t <= k; t+=2)
        (ans += dp[n % 2][60][t]) %= MOD;
    cout << ans;
}