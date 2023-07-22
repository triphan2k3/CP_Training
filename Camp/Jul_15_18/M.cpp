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

double a[30][30];
double dp[1 << 21];
int touch[1 << 21];
int fullMask, n;

double call(int mask) {
    if (mask == fullMask)
        return 1;
    if (touch[mask])
        return dp[mask];
    int numbit = __builtin_popcount(mask);
    for (int i = 0; i < n; i++)
        if ((mask & (1 << i)) == 0) {
            double prob = call(mask | (1 << i));
            double sum = 0;
            for (int j = 0; j < n; j++) 
                if (mask & (1 << j))
                    sum += a[j][i];
            dp[mask] += prob * sum / (numbit * (numbit + 1) / 2);
        }
    touch[mask] = 1;
    return dp[mask];
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    cin >> n;
    FOr(i, 0, n) FOr(j, 0, n)
        cin >> a[i][j];
    fullMask = (1 << n) - 1;
    FOr(i, 0, n)
        cout << setprecision(6) << fixed << call(1 << i) << " ";
}