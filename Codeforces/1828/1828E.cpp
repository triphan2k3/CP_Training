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
const int MOD1=1e9+7;
const int MOD2=1e9+9;
const int BASE = 1702;
const ll INF=(ll)1e18+7;

vector<ii> buildHash(string s, bool rev) {
    if (rev)
        reverse(s.begin(), s.end());
    vector<ii> h(s.size() + 1);
    for(int i = 1; i <= s.size(); i++) {
        h[i] = {
            (h[i - 1].F * 1LL * BASE + s[i - 1]) % MOD1,
            (h[i - 1].S * 1LL * BASE + s[i - 1]) % MOD2
        };
    }
    return h;
}
ii lt[N];
ii getHash(vector<ii> &h, int l, int r, bool rev) {
    if (l > r) 
        return {0, 0};
    if (rev) {
        int n = h.size() - 1;
        l = n - l + 1;
        r = n - r + 1;
        swap(l, r);
    }
    return {
        (h[r].F - (h[l].F * 1LL * lt[r - l].F % MOD1) + MOD1) % MOD1,
        (h[r].S - (h[l].S * 1LL * lt[r - l].S % MOD2) + MOD2) % MOD2,
    };
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; t = 1;
    cin >> t; 
    lt[0] = {1, 1};
    FOR(i, 1, 1e6) {
        lt[i] = {
            lt[i - 1].F * 1LL * BASE % MOD1,
            lt[i - 1].S * 1LL * BASE % MOD2,
        };
    }

    while (t--) {
        int n; n = 500000; 
        cin >> n;
        string s; 
        cin >> s;
        // FOR(i, 1, n) s.push_back('a');
        vector<int> l(n + 1, 0), r(n + 1, 0), e(n + 1, 0);
        vector<ii> h = buildHash(s, 0), rh = buildHash(s, 1);    
        vector<vector<int>> seg;
        seg.resize(n + 1);
        FOr(i, 1, n) {
            int L = 0;
            int R = min(i, n - i);
            int res = 0;
            while (L <= R) {
                int M = (L + R) >> 1;
                if (getHash(h, i - M + 1, i + M, 0 ) == 
                    getHash(rh, i - M + 1, i + M, 1)) {
                        res = M;
                        L = M + 1;
                    } else 
                        R = M - 1;
            }
            // cerr << i << "\n";
            if (res == 0) continue;
            seg[i - res + 1].push_back(i);
            if (i + res + 1 <= n)
                seg[i + res + 1].push_back(-i);
        }
        FOR(i, 1, n)
            sort(seg[i].begin(), seg[i].end());
        set<int> S;
        FOR(i, 1, n) {
            for (int x:seg[i])
                if (x < 0)
                    S.erase(-x);
                else
                    S.insert(x);
            if (S.empty()) continue;
            if (*S.rbegin() < i) continue;
            e[i - 1] = i + (*(S.lower_bound(i)) - i) * 2;
        }

        vector<int> used(n, 0);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            if (used[i] || e[i] == 0)
                continue;
            used[i] = 1;
            int j = e[i];
            int cnt = 1;
            while (j + 1 < n && e[j + 1]) {
                used[j + 1] = 1;
                ++cnt;
                j = e[j + 1];
            }
            ans += 1LL * cnt * (cnt + 1) / 2;
        }
        cout << ans << "\n";
    }
}