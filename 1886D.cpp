#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOr(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define FOd(i, a, b) for (int i = a; i > b; i--)
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N = 1e6 + 7;
const int MOD = 998244353;
const ll INF = (ll)1e18 + 7;

template <typename T>
struct Combine {
    vector<T> lt;
    vector<T> inv;
    T mod;
    Combine(T n, T mod = 998244353) {
        this->mod = mod;
        lt = vector<T>(n + 1, 1);
        inv = vector<T>(n + 1, 1);
        for (T i = 1; i <= n; i++)
            lt[i] = lt[i - 1] * 1LL * i % mod;
        inv[n] = 1;
        for (T i = mod - 2, base = lt[n]; i; i >>= 1) {
            if (i & 1)
                inv[n] = inv[n] * 1LL * base % mod;
            base = base * 1LL * base % mod;
        }

        for (T i = n - 1; i > 0; i--)
            inv[i] = inv[i + 1] * 1LL * (i + 1) % mod;
    }

    T fPow(T a, T b) {
        if (b == 1)
            return a;
        T c = fPow(a, b / 2);
        c = 1LL * c * c % mod;
        if (b % 2)
            c = 1LL * c * a % mod;
        return c;
    }

    T fInv(T n) {
        T ans = 1;
        for (T i = mod - 2; i; i >>= 1) {
            if (i & 1)
                ans = ans * 1LL * n % mod;
            n = n * 1LL * n % mod;
        }
        return ans;
    }

    T Inv(T n) {
        if (n >= lt.size())
            return -1;
        return inv[n];
    }

    T Lt(T n) {
        if (n >= lt.size())
            return -1;
        return lt[n];
    }

    T nCk(T n, T k) {
        if (k > n || n >= lt.size())
            return 0;
        return lt[n] * 1LL * inv[k] % mod * inv[n - k] % mod;
    }

    T nAk(T n, T k) {
        if (k > n || k <= 0 || n <= 0)
            return 1;
        return lt[n] * 1LL * inv[n - k] % mod;
    }

    void test() {
        for (T i = 1; i < lt.size(); i++)
            cout << lt[i] << " ";
        cout << "\n";
        for (T i = 1; i < lt.size(); i++)
            cout << 1LL * lt[i] * inv[i] % mod << " ";
    }
};

int n, m;

// #define TriPhan

int main() {
#ifdef TriPhan
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    Combine<ll> com(1e6, 998244353);
    cin >> n >> m;
    int lst = n + 1;
    string s;
    cin >> s;
    s = "  " + s;
    set<pair<int, int>> S;
    for (int i = n; i >= 2; i--) {
        if (s[i] != '?') {
            S.insert({i, lst - 1});
            lst = i;
        }
    }
    S.insert({1, lst - 1});

    ll ans = 1;
    for (auto it = S.begin(); it != S.end(); ++it) {
        int l = (*it).F, r = (*it).S;
        if (r == 1)
            continue;
        ans *= com.nAk(r - 2, r - l);
        ans %= MOD;
    }
    if (lst == 2)
        cout << ans << "\n";
    else
        cout << "0\n";
    for (int i = 1; i <= m; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        ++pos;
        if (s[pos] == '?' && c != '?') {
            auto del = prev(S.lower_bound({pos, pos}));
            int oldL = (*del).F;
            int oldR = (*del).S;
            int newR = pos - 1;
            int newL = pos;
            ans *= com.fInv(com.nAk(oldR - 2, oldR - oldL));
            ans %= MOD;
            ans *= com.nAk(newR - 2, newR - oldL);
            ans %= MOD;
            ans *= com.nAk(oldR - 2, oldR - newL);
            ans %= MOD;
            S.erase(del);
            S.insert({oldL, newR});
            S.insert({newL, oldR});
        } else if (s[pos] != '?' && c == '?') {
            auto del2 = S.lower_bound({pos, pos});
            auto del1 = prev(del2);
            int l1 = (*del1).F, r1 = (*del1).S;
            int l2 = (*del2).F, r2 = (*del2).S;
            ans *= com.fInv(com.nAk(r2 - 2, r2 - l2));
            ans %= MOD;
            ans *= com.fInv(com.nAk(r1 - 2, r1 - l1));
            ans %= MOD;
            ans *= com.nAk(r2 - 2, r2 - l1);
            ans %= MOD;
            S.erase(del1);
            S.erase(S.lower_bound({pos, pos}));
            S.insert({l1, r2});
        }
        s[pos] = c;
        if ((*S.begin()).S != 1) {
            cout << "0\n";
        } else
            cout << ans << "\n";
    }
}