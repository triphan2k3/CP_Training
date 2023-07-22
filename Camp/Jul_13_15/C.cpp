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
    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;
    vector<int> w(n + 1, 0);
    FOR(i, 1, n) {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    long long ans = INF;
    FOR(nl, 0, n) {
        int nr = n - nl;
        if (nl > nr) {
            ll costL = 1LL * w[nl] * l + (nl - nr - 1) * Ql;
            ll costR = 1LL * (w[n] - w[nl]) * r;
            ans = min(ans, costL + costR);
        } else if (nl == nr) {
            ll costL = 1LL * w[nl] * l;
            ll costR = 1LL * (w[n] - w[nl]) * r;
            ans = min(ans, costL + costR);
        } else {
            ll costL = 1LL * w[nl] * l;
            ll costR = 1LL * (w[n] - w[nl]) * r + (nr - nl - 1) * Qr;
            ans = min(ans, costL + costR);
        }
    }
    cout << ans;
}