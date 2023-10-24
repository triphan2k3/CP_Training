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

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a(m + 2);
        a[0] = 1;
        FOR(i, 1, m) cin >> a[i];
        a[m + 1] = n + 1;
        int ncookie = m + (a[1] != 1);
        FOR(i, 1, m + 1) {
            if (a[i] == a[i - 1])
                continue;
            ncookie += (a[i] - a[i - 1] - 1) / d;
        }
        int mi = MOD;
        int miId = -1;
        if (a[1] == 1) {
            mi = ncookie;
            miId = 1;
        }
        FOR(i, 1, m) {
            if (a[i] == a[i - 1])
                continue;
            int newCookie = ncookie - 1 - (a[i] - a[i - 1] - 1) / d - (a[i + 1] - a[i] - 1) / d
                             + (a[i + 1] - a[i - 1] - 1) / d;
            if (newCookie < mi) {
                mi = newCookie;
                miId = i;
            }
        }
        int cnt = 0;
        if (a[1] == 1 && mi == ncookie)
            cnt++;
        FOR(i, 1, m) {
            if (a[i] == a[i - 1])
                continue;
            int newCookie = ncookie - 1 - (a[i] - a[i - 1] - 1) / d - (a[i + 1] - a[i] - 1) / d
                             + (a[i + 1] - a[i - 1] - 1) / d;
            if (newCookie == mi)
                ++cnt;
        }

        cout << mi << " "<< cnt << "\n";

    }
}