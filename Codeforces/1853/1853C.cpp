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

ll n, k;
ll a[N];

ll candel(ll an, ll maxpos, ll n) {
    if (maxpos < an) return 0;
    return min(k, 1 + (maxpos - an) / n);
}

int check(ll mid) {
    int tempn = n;
    FOD(i, n, 1) {
        mid -= candel(a[i], mid, tempn);
        --tempn;
    }
    return mid > 0;
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
        cin >> n >> k;
        // n = 200000;
        FOR(i, 1, n)
            // a[i] = i;
            cin >> a[i];
        ll l = 1, r = 1LL * n * k;
        ll ans = r + 1;
        check(3);
        while (l <= r) {
            ll m = (l + r) >> 1;
            if (check(m)) {
                ans = m;
                r = m - 1;
            } else 
                l = m + 1;
        }
        cout << ans << "\n";        
    }
}