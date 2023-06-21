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

struct Combine {
    vector<int> lt;
    vector<int> inv;
    int mod;
    Combine(int n, int mod = 1e9+7) {
        this->mod = mod;
        lt = vector<int> (n + 1, 1);
        inv = vector<int> (n + 1, 1);
        for (int i = 1; i <= n; i++)
            lt[i] = lt[i - 1] * 1LL * i % mod;
        inv[n] = 1;
        for (int i = mod - 2, base = lt[n]; i; i >>= 1) {
            if (i & 1)
                inv[n] = inv[n] * 1LL * base % mod;
            base = base * 1LL * base % mod;
        }

        for (int i = n - 1; i > 0; i--)
            inv[i] = inv[i + 1] * 1LL * (i + 1) % mod;
    }

    int Inv(int n) {
        if (n >= lt.size())
            return -1;
        return inv[n];
    }

    int Lt(int n) {
        if (n >= lt.size())
            return -1;
        return lt[n];
    }

    int nCk(int n, int k) {
        if (k > n || n >= lt.size())
            return -1;
        return lt[n] * 1LL * inv[k] % mod * inv[n - k] % mod;
    }
    void test() {
        for (int i = 1; i < lt.size(); i++)
            cout << lt[i] << " ";
        cout << "\n";
        for (int i = 1; i < lt.size(); i++)
            cout << 1LL * lt[i] * inv[i] % MOD << " ";
    }
};

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0,LLONG_MAX);

Combine cmb(6e5, 998244353);
int numWay(int n) {
    if (n == 0) return 1;
    if (n % 2)
        return 0;
    n /= 2;
    return cmb.Lt(2 * n) * 1LL * cmb.Inv(n + 1) % cmb.mod * cmb.Inv(n) % cmb.mod;
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
        int n, k;
        cin >> n >> k;
        vector<ll> h(n + 1, 0);
        FOR(i, 1, k) {
            int o, c;
            cin >> o >> c;
            --o, --c;
            ll Hash = rnd(gen);
            h[o] ^= Hash;
            h[c + 1] ^= Hash;
             
        }
        FOR(i, 1, n - 1)
            h[i] ^= h[i - 1];
        map<ll, int> freq;
        FOr(i, 0, n)
            freq[h[i]]++;
        int ans = 1;
        for (auto item:freq)
            ans = ans * 1LL * numWay(item.second) % cmb.mod;
        cout << ans << "\n";
    }
}
/*
(.(.......().)...())........
*/