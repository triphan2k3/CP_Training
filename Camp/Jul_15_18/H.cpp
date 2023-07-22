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

double dp[2001][2001];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, t;
    double p;
    cin >> n >> p >> t;
    dp[0][0] = 1; // start is no one
    FOR(i, 1, t) {
        dp[i][0] = dp[i-1][0] * (1 - p);
        FOR(j, 1, i) 
            dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
    }
    double ans = 0;
    FOR(i, 1, t)
        ans += dp[t][i] * min(n, i);
    cout << ans;
}