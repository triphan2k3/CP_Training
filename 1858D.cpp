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

const int N=3e3+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int dp0[2][N][N];
int dp1[2][N][N];
int a[N];

void maximize(int &a, int b) {
    a = max(a, b);
}

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
        int n, k; cin >> n >> k;
        string s;
        cin >> s;
        s = "." + s + ".";
        int pre0 = 0, pre1 = 0;
        FOR(_, 0, 1) {
        FOR(i, 1, n) FOR(j, 0, k) {
            if (j) {
                dp0[_][i][j] = dp0[_][i][j - 1];
                dp1[_][i][j] = dp1[_][i][j - 1];
            }
            
            if (s[i] == '0') {
                maximize(dp0[_][i][j], dp0[_][i - 1][j] + 1);
                maximize(dp1[_][i][j], dp1[_][i - 1][j - 1] + 1);
            } else {
                maximize(dp1[_][i][j], dp1[_][i - 1][j] + 1);
                maximize(dp0[_][i][j], dp0[_][i - 1][j - 1] + 1);
            }
        }
        reverse(all(s));
        }
        FOR(a, 1, n) {
            int ans = 0;
            FOR(l, 0, k) {
                FOR(_, 0, 1) {
                    ans = max(ans, dp0[_][n][l] * a + dp1[1 - _][n][k - l]);
                }
            }
            cout << ans  << " ";
        }
        cout << "\n";
    }

}