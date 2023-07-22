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
int dp[2][800];
vector<int> tile[N];

int getTile(int col, int from) {
    if (tile[col].size() == 0)
        return 0;
    return tile[col].end() - lower_bound(all(tile[col]), from);
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, K;
    cin >> n >> K;
    map<ii, bool> c;
    for (int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        tile[n - b + 1].push_back(n - a + 1);
        // cout << n - b + 1 << " " << n - a + 1 << "\n";
    }
    for (int i = 1; i <= n; i++) 
        sort(all(tile[i]));


    for (int i = 1; i <= n; i++) {
        dp[i % 2][0] = min(0LL + dp[(i + 1) % 2][0] + getTile(i, 1) * 3, 1LL * i * (i + 1) / 2 + 2);
        for (int k = 1; k < i && k * (k + 1) <= 6 * K; k++)
            dp[i % 2][0] = min(dp[i % 2][0], dp[(i + 1) % 2][k - 1] + k * (k + 1) / 2 + 2 + 3 * getTile(i, k + 1));

        for (int j = 1; j <= i && j * (j + 1) <= 6 * K; j++)
            dp[i % 2][j] = min(dp[(i + 1) % 2][j - 1] + getTile(i, j + 1) * 3, dp[i % 2][j - 1]);
    }
    cout << dp[n % 2][0];
}