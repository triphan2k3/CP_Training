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

int a[N];
int n;
int cnt[N][32];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    cin >> n;
    // FOR(i, 0, 31) cnt[0][i] = 1;
    FOR(i, 1, n) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        for (int j = 0, x = a[i]; x; j++) {
            cnt[i][j] = x & 1;
            x >>= 1;
        }
    }
    FOR(i, 1, n)
        FOR(j, 0, 31)
            cnt[i][j] += cnt[i - 1][j];
    int ans = 0;

    for (int r = 1; r <= n; r++) {
        for (int k = 0; k <= 31; k++) {
            int mask = 1 << k;
            int num = cnt[r - 1][k];
            if (a[r] & (1 << k)) 
                ans = (ans + 1LL * mask * (r - num) % MOD * (r + 1)) % MOD;
            else 
                ans = (ans + 1LL * mask * num % MOD * (r + 1)) % MOD;
        }
    }

    for (int l = 1; l <= n; l++) {
        for (int k = 0; k <= 31; k++) {
            int mask = 1 << k;
            int num = cnt[n][k] - cnt[l - 1][k];
            if (a[l - 1] & (1 << k))
                ans = (ans - 1LL * mask * (n - l + 1 - num) % MOD * l) % MOD;
            else 
                ans = (ans - 1LL * mask * num % MOD * l) % MOD;
            if (ans < 0) ans += MOD;
        }
    }
    cout << ans;
    
}