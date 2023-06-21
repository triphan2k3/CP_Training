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

vector<int> c[N];

int cnt(int val, vector<int> &a) {
    return upper_bound(a.begin(), a.end(), val) - lower_bound(a.begin(), a.end(), val);
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
        vector<int> a(n), b(n);
        FOR(i, 1, n)
            cin >> a[i - 1];
        FOR(j, 1, n)
            cin >> b[j - 1];
        FOR(i, 1, n)
            c[a[i - 1]].pb(b [i - 1]);
        FOR(i, 1, n)
            sort(all(c[i]));
        ll ans = 0;
        FOR(ai, 1, n) {
            FOR(aj, ai + 1, min(n, 2 * n/ai)) {
                int tai = ai;
                int taj = aj;
                if (c[tai].size() > c[taj].size())
                swap(tai, taj);
                for(int bi:c[tai]) {
                    ans += cnt(tai * taj - bi, c[taj]);
                }
            }
            if (1LL * ai * ai > 2 * n)
                continue;
            ll tans = 0;
            int flag = 1;
            for(int bi:c[ai]) {
                int t = cnt(ai * ai - bi, c[ai]);
                if (bi * 2 == ai * ai) {
                    if (flag)
                        ans += (1LL * t * (t - 1)) / 2;
                    flag = 0;
                }
                else 
                    tans += cnt(ai * ai- bi, c[ai]);
            }
            tans /= 2;
            ans += tans;
        }
        cout << ans << "\n";
        FOR(i, 1, n)
            c[i].clear();
    }
}