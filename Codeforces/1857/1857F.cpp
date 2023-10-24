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
 
int getNum(vector<ll> &a, int val) {
    return upper_bound(all(a), val) - lower_bound(all(a), val);
}
 
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
        int n; cin >> n;
        vector<ll> a(n);
        for (ll &x:a) cin >> x;
        sort(all(a));
        int q; cin >> q;
        while (q--) {
            ll x, y;
            cin >> x >> y;
            // aj^2 - xaj + y = 0
            ll delta = x * x - 4 * y;
            ll sqrtD = sqrt(delta);
            if (sqrtD * sqrtD != delta) {
                cout << "0 ";
                continue;
            }
            // (-b +- sqrtD) / 2
            ll ai = (x + sqrtD) / 2;
            ll aj = (x - sqrtD) / 2;
            int numi = getNum(a, ai);
            int numj = getNum(a, aj);
            ll ans = 0;
            if (ai + aj == x && ai * aj == y) {
                if (ai == aj) 
                    ans = 1LL * numi * (numi - 1) / 2;
                else 
                    ans = 1LL * numi * numj;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    
}