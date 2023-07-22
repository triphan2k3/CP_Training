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

int nxt[N][10];
int dp[2][10];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        string s, l, r;
        int m;
        cin >> s >> m >> l >> r;
        int n = s.size();
        vector<int> last(10, n);
        FOR(i, 0, 9)
            nxt[n][i] = nxt[n + 1][i] = n;
        for (int i = n - 1; i >= 0; i--) {
            last[s[i] - '0'] = i;
            FOR(j, 0, 9)
                nxt[i][j] = last[j];
        }
        for (int i = l[0]; i <= r[0]; i++)
            dp[0][i - '0'] = nxt[0][i - '0'];

        for (int i = 1; i < m; i++) 
            for (int j = l[i] ; j <= r[i]; j++) {
                int thisDig = j - '0';
                dp[i % 2][thisDig] = 0;
                for (int k = l[i - 1]; k <= r[i - 1]; k++) {
                    dp[i % 2][thisDig] = max(dp[i % 2][thisDig], nxt[dp[(i - 1) % 2][k - '0'] + 1][thisDig]);
            }
        }
        string ans = "NO\n";
        for (int i = l.back(); i <= r.back(); i++)
            if (dp[(m - 1) % 2][i - '0'] == n)
                ans = "YES\n";
        cout << ans;
        

    }
}