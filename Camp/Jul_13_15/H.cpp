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

vector<int> val;
vector<iii> trace;

void prepare() {
    for (int i = 0; i <= 6; i++)
        for (int j = 0; j + i <= 6; j++) {
            int k = 6 - i - j;
            val.push_back(j * 4 + k * 7);
            // cout << val.back() << " ";
            trace.push_back({{i,j},k});
        }
}

map<ii, iii> trc;

int dp(int pos, int rem, vector<int> &a) {
    if (pos == a.size()) {
        return rem == 0;
    }
    for (int i = 0; i < val.size(); i++) {
        int x = val[i];
        if ((rem + x) % 10 != a[pos]) continue;
        int nrem = (rem + x) / 10;
        if (dp(pos + 1, nrem, a)) {
            trc[{pos + 1, nrem}] = {{pos, rem}, i};
            return 1;
        }
    }
    return 0;
}


int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    prepare();
    int t;
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<int> a;
        while (n) {
            a.push_back(n % 10);
            n/=10;
        }
        trc.clear();
        if (dp(0, 0, a) == 0) {
            cout << "-1\n";
            continue;
        }
        vector<ll> ans(6, 0);
        for (ii state = {a.size(), 0}; ; state = trc[state].F) {
            if (state.F == 0) break;
            int id = trc[state].S;
            int n0 = trace[id].F.F;
            int n4 = trace[id].F.S;
            int n7 = trace[id].S;
            id = 0;
            FOR(i, 1, n0) {
                ans[id] *= 10;
                ++id;
            }
            FOR(i, 1, n4)
                ans[id] = ans[id] * 10 + 4, ++id;
            FOR(i, 1, n7)
                ans[id] = ans[id] * 10 + 7, ++id;
        }
        for (ll x:ans)
            cout << x << " ";
        cout << "\n";
    }
}