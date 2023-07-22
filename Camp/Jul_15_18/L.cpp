#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORR(i, a, b, j, c, d) for(int i=a; i<=b; i++) for(int j=c; j<=d; j++)
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

double dp[101][101][101][3];

inline void battle(int f, int s, vector<int> &b) {
    if (s == 2 && f == 0) b[f] = 1;
    if (s == 2 && f == 1) b[s] = 1;
    if (s == 1 && f == 0) b[s] = 1; 
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int x, y, z;
    std::cin >> x >> y >> z;
    FORR(i, 0, x, j, 0, y)
    FORR(k, 0, z, l, 0, 2) {
        int a[3] = {i, j, k};
        if (a[0] + a[1] + a[2] == 0)
            continue;

        // impossible
        if (a[l] == 0) {
            dp[i][j][k][l] = 0;
            continue;
        }

        //surely
        int sum = i + j + k;
        if (sum == a[l]) {
            dp[i][j][k][l] = 1;
            continue;
        }

        double res = 0;
        FORR(f, 0, 2, s, f + 1, 2) {
            if (f == s) continue;
            if (a[f] == 0 || a[s] == 0) continue;
            vector<int> b(3, 0);
            battle(f, s, b);
            res += 2 * a[f] * a[s] * dp[i - b[0]][j - b[1]][k - b[2]][l];
        }

        dp[i][j][k][l] = res / (sum * (sum - 1) -  i * (i - 1) - j * (j - 1) - k * (k - 1));
        // cout << i<<j<<k<<l<<" " << dp[i][j][k][l] << "\n";
    }
    FOR(t, 0, 2)
        std::cout << setprecision(9) << fixed << dp[x][y][z][t] << " ";

}