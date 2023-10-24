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

struct Combine {
    vector<int> lt;
    vector<int> inv;
    int mod;
    Combine(int n, int mod = 1e9+7) {
        lt = vector<int> (n + 1, 1);
        inv = vector<int> (n + 1, 1);
        for (int i = 1; i <= n; i++)
            lt[i] = lt[i - 1] * 1LL * i % mod;
        inv[n] = 1;
        for (int i = mod - 2, base = lt[n]; i; i >>= 1) {
            if (i & 1)
                inv[n] = inv[n] * 1LL * base % mod;
            base = base * 1LL * base % mod;
        }

        for (int i = n - 1; i > 0; i--)
            inv[i] = inv[i + 1] * 1LL * (i + 1) % mod;
    }

    int fpow(int a, int b) {
        if (b == 0)
            return 1;
        int tmp = fpow(a, b/2);
        tmp = 1LL * tmp * tmp % MOD;
        if (b % 2)
            tmp = 1LL * tmp * a % MOD;
        return tmp;
    }

    int Inv(int n) {
        if (n >= lt.size())
            return -1;
        return inv[n];
    }

    int Lt(int n) {
        if (n >= lt.size())
            return -1;
        return lt[n];
    }

    int nCk(int n, int k) {
        if (k > n || n >= lt.size())
            return -1;
        return lt[n] * 1LL * inv[k] % mod * inv[n - k] % mod;
    }
    void test() {
        for (int i = 1; i < lt.size(); i++)
            cout << lt[i] << " ";
        cout << "\n";
        for (int i = 1; i < lt.size(); i++)
            cout << 1LL * lt[i] * inv[i] % MOD << " ";
    }
};

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
    Combine comb(k, 998244353);
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
    dp[0][0] = 1;
    vector<int> suffix(k + 1, 0);
    FOR(i, 1, n) {
        FOR(j, 1, min(i, k)) {
            dp[i][j] = suffix[j] + 1LL * dp[i - 1][j - 1] * (k - (j - 1)) % MOD;
            dp[i][j] %= MOD;
        }
        // suffix[k] = dp[i][k];
        FOD(j, k - 1, 1)
            suffix[j] = (suffix[j + 1] + dp[i][j]) % MOD;
        dp[i][0] = dp[i][k];
    }
    int ans = 0;
    FOR(i, k, n) {
        ans += 1LL * dp[i][k] * comb.fpow(k, n - i) % MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}