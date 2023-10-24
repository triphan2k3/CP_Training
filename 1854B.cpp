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
#define int long long
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;


const int N=2e5+2;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

bitset<N> dp[2], mask, total;
int a[N];
int n;

main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];
    dp[0][1] = 1;
    total[1] = 1;
    mask.set();
    FOR(i, 1, n) {
        int curI = i % 2;
        int preI = (i + 1) % 2;
        dp[curI] = dp[preI] | (dp[preI] << a[i]);
        mask >>= 1;
        total |= dp[curI];
        dp[curI][i] = 0;
    }
    // chang N before submit
    FOR(i, 1, 2 * n)
        a[i] += a[i - 1];
    int ans = 0;
    FOR(i, 1, 2 * n)
        if (total[i])
            ans = max(ans, a[i] - i + 1);
    cout << ans;
}