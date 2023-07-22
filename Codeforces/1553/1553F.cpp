#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define FORD(i, r, l) for (int i = (r); i >= (l); --i)
#define DB(X) { cerr << #X << " = " << (X) << '\n'; }
#define DB1(A, _) { cerr << #A << "[" << _ << "] = " << (A[_]) << '\n'; }
#define DB2(A, _, __) { cerr << #A << "[" << _ << "][" << __ << "] = " << (A[_][__]) << '\n'; }
#define DB3(A, _, __, ___) { cerr << #A << "[" << _ << "][" << __ << "][" << ___ << "] = " << (A[_][__][___]) << '\n'; }
#define PR(A, l, r) { cerr << '\n'; FOR(_, l, r) DB1(A, _); cerr << '\n';}
#define sz(x) ((int) (x).size())
#define pb push_back
#define eb emplace_back
#define pf push_front
#define F first
#define S second
#define next ___next
#define prev ___prev
#define y1 ___y1
#define left ___left
#define right ___right
#define y0 ___y0
#define div ___div

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;

typedef pair<ll, ll> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vl;
const int N = 2e5 + 3, NN = 3e5;
int n, a[N];
ii bit[NN + 2];
void upd(int p, int v)
{
    for (; p <= NN; p += p & -p) bit[p].F += v, bit[p].S++;
}
ii query(int p)
{
    ll res = 0;
    int num = 0;
    for (; p > 0; p -= p & -p) res += bit[p].F, num += bit[p].S;
    return {res, num};
}
int main()
{
#ifdef HynDuf
    freopen("inp.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    set<int> s;
    ll ans = 0;
    s.insert(a[1]);
    upd(a[1], a[1]);
    cout << "0 ";
    FOR(i, 2, n)
    {
        // 1 -> i - 1  % a[i]
        ans += query(a[i] - 1).F;
        auto lst = s.lower_bound(a[i]);
        while (1)
        {
            if (lst == s.end()) break;
            int j = *lst / a[i];
            // DB(j)
            // a[i] * j -> a[i] * (j + 1) - 1
            auto it = s.lower_bound(a[i] * (j + 1));
            it--;
            ii tem = query(*it);
            ii tem1 = query(*lst - 1);
            tem = {tem.F - tem1.F, tem.S - tem1.S};
            assert(tem.F >= tem.S * j * a[i]);
            ans += tem.F - tem.S * j * a[i];
            lst = it;
            lst++;
        }
        // DB(ans);
        // a[i] %  1->i-1
        ans += (query(NN).S - query(a[i]).S) * a[i];
        lst = s.begin();
        // DB(i)
        while (1)
        {
            if (lst == s.end() || *lst >= a[i]) break;
            int j = a[i] / *lst;
            // DB(j)
            // a[i] / j <- a[i] / (j + 1) + 1
            auto it = s.upper_bound(a[i] / j);
            it--;
            ii tem = query(*it);
            ii tem1 = query(*lst - 1);
            tem = {tem.F - tem1.F, tem.S - tem1.S};
            assert(tem.F * j <= tem.S * a[i]);
            // DB(tem.F)
            // DB(tem.S)
            // DB(tem.F * j - tem.S * a[i]);
            ans += tem.S * a[i] - tem.F * j;
            lst = it;
            lst++;
        }
        // DB(ans);
        s.insert(a[i]);
        upd(a[i], a[i]);
        cout << ans << ' ';
    }
    return 0;
}
