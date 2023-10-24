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
const int MOD=998244353;
const ll INF=(ll)1e18+7;

iii e[N];

class dsu {
    public:
    vector<int> p;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n+1, -1);
    }

    int get(int x) {
        return (p[x] < 0 ? x : (p[x] = get(p[x])));
    }

    int getSize(int x) {
        return -p[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return false;
        if (x < y) swap(x, y);
        p[y] += p[x];
        p[x] = y;
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

bool cmp(iii a, iii b) {
    return a.second < b.second;
}

int lt(int a, int b) {
    if (a <= 0) return 0;
    if (b == 0)
        return 1;
    int tmp = lt(a, b / 2);
    tmp = 1LL * tmp * tmp % MOD;
    if (b % 2)
        tmp = 1LL * tmp * a % MOD;
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
    int t; cin >> t;
    while (t--) {
        int n, S; cin >> n >> S;
        vector<iii> a(n - 1);
        FOr(i, 0, n - 1)
            cin >> a[i].F.F >> a[i].F.S >> a[i].S;
        sort(all(a), cmp);
        dsu d(n);
        int ans = 1;
        for(iii x:a) {
            int u = x.F.F;
            int v = x.F.S;
            int w = x.S;
            if (d.same(u, v)) continue;
            int s1 = d.getSize(u);
            int s2 = d.getSize(v);
            d.unite(u, v);
            if (s1 == 1 && s2 == 1) continue;
            int numEdge = (1LL * s1 * s2 - 1) % (MOD - 1);
            ans = 1LL * ans * lt(S - w + 1, numEdge) % MOD;
        }
        cout << ans << "\n";
    }
}