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

const int N=15;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int n;
int a[N];
int dp[N][N], ma[N][N], mi[N][N];
int f[2][N][N];

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
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        
        a[n + 1] = n + 1; 
        a[0] = 0;

        FOR(i, 0, n + 1) FOR(j, 0, n) dp[i][j] = N + 1;
        FOR(i, 0, n) dp[0][i] = 0;

        
        FOR(i, 1, n + 1)
            FOR(j, 0, n) {
                if (a[i] > a[i - 1])
                    dp[i][j] = dp[i - 1][j];
                if (j)
                    FOR(k, 0, i - 1)
                        if (a[k] < a[i])
                            dp[i][j] = min(dp[i][j], dp[k][j - 1] + i - k - 1);
            }
        FOR(k, 1, n)
            cout << dp[n + 1][k] << " ";
        cout << "\n"; 
    }
}