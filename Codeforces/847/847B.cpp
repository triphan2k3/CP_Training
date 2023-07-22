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

const int N=17;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int a[N];
int it[4 * N];

void build(int i, int l, int r) {
    if (l == r) {
        it[i] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build((i<<1) + 1, m + 1, r);
    it[i] = max(it[i << 1], it[(i << 1) + 1]);
    return;
}

void update(int i, int l, int r, int pos) {
    if (l > pos || r < pos)
        return;
    if (l == r) {
        it[i] = 0;
        return;
    }
    int m = (l + r) >> 1;
    update(i << 1, l, m, pos);
    update((i<<1) + 1, m + 1, r, pos);
    it[i] = max(it[i << 1], it[(i << 1) + 1]);
}

int getmax(int i, int l, int r, int L, int R) {
    if (l > R || r < L)
        return 0;
    if (L <= l && R >= r)
        return it[i];
    int m = (l + r) >> 1;
    int lef = getmax(i << 1, l, m, L, R);
    int rig = getmax((i << 1) | 1, m + 1, r, L, R);
    return max(lef, rig);
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 1);
    reverse(pos.begin(), pos.end());
    while (pos.size()) {
        int prev = pos.back();
        pos.pop_back();
        cout << a[prev] << " ";
        while (prev != n + 1) {
            int l = prev + 1, r = n;
            int ans = n + 1;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (getmax(1, 1, n, l, m) < a[prev]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                    ans = m;
                }
            }
            if (ans != n + 1) {
                cout << a[ans] << " ";
                update(1, 1, n, ans);

            }
            a[prev] = 0;
            prev = ans;
        }
        a[prev] = 0;
        cout << "\n";
        while (pos.size() && a[pos.back()] == 0) pos.pop_back();
    }
}