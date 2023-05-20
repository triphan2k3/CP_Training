#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

ll lt(int a, int b) {
    if (b == 0) return 1;
    ll tmp = lt(a, b / 2);
    tmp = (tmp * tmp) % MOD;
    if (b % 2)
        tmp = (tmp * a) % MOD;
    return tmp;
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int &x:a)
            cin >> x;
        sort(a.begin(), a.end());
        b[0] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1])
                b[i] = b[i - 1];
            else if (a[i] == a[i - 1] + 1)
                b[i] = b[i - 1] + 1;
            else 
                b[i] = b[i - 1] + 2;
        }
        vector<int> cnt(b[n - 1] + 1, 0);
        FOr(i, 0, n)
            cnt[b[i]]++;
        ll ans = 0;
        ll prod = cnt[1];
        int i = 1, j = 1;
        while (j <= b[n - 1]) {
            if (prod == 0) {
                j++;
                i = j;
                prod = cnt[j];
            }
            while (j - i + 1 < m && j < b[n - 1]) {
                ++j;
                if (cnt[j] == 0) {
                    prod = 0;
                    break;
                }
                prod = prod * cnt[j] % MOD;
            }
            if (prod == 0) {
                if (j == b[n-1]) break;
                continue;
            }
            if (j - i + 1 == m) {
                (ans += prod) %= MOD;
                (prod *= lt(cnt[i], MOD - 2)) %= MOD;
                ++i;
            }
            if (j == b[n-1]) break;
        }
        cout << ans << "\n";

    }
}