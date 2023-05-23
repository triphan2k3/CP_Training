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
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int p[N][20];
int tin[N], tou[N], h[N];
int c;
int IT[4*N];

int get(int i, int L, int R, int l, int r) {
    if (L > r || R < l) return 0;
    if (L >= l && r >= R)
        return IT[i];
    int M = (L + R) >> 1;
    return 
        get(i << 1, L, M, l, r) +
        get((i << 1) | 1, M + 1, R, l, r);
}

void update(int i, int L, int R, int pos) {
    if (L > pos || R < pos)
        return;
    if (L == R) {
        IT[i]++;
        return;
    }
    int M = (L + R) >> 1;
    update(i << 1, L, M, pos);
    update((i << 1) | 1, M + 1, R, pos);
    IT[i] = IT[i << 1] + IT[(i << 1) | 1];
    return;
}


void dfs(int u) {
    tin[u] = ++c;
    for (int v:a[u]) {
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v);
    }
    tou[u] = ++c;
    return;
}

void prepare(int n) {
    FOR(k, 1, 19)
        FOR(u, 1, n)
            if (h[u] >= (1 << k))
                p[u][k] = p[p[u][k - 1]][k - 1];
    FOR(i, 1, 8 * n)
        IT[i] = 0;

    return;    
}

bool insubtree(int r, int c) {
    return tin[r] < tin[c] && tou[r] > tou[c];
}

int jump(int u, int step) {
    FOD(i, 19, 0)
        if (step & (1 << i))
            u = p[u][i];
    return u;
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
        c = 0;
        FOR(i, 1, n)
            a[i].clear();
        FOR(i, 2, n) {
            int u; cin >> u;
            a[u].push_back(i);
        }
        dfs(1);
        prepare(n);
        update(1, 1, tou[1], tin[1]);
        int msize = 0;
        int centroid = 1;
        FOR(i, 2, n) {
            if (insubtree(centroid, i)) {
                int v = jump(i, h[i] - h[centroid] - 1);
                int vsize = get(1, 1, tou[1], tin[v], tou[v]) + 1;
                if (vsize > i / 2) {
                    centroid = v;
                    msize = i - vsize;
                } else if (vsize > msize) {
                    msize = vsize;
                }
            } else {
                int csize = get(1, 1, tou[1], tin[centroid], tou[centroid]);
                int rsize = i - csize;
                if (rsize > i / 2) {
                    centroid = p[centroid][0];
                    msize = csize;
                } else if (rsize > msize)
                    msize = rsize;
            }
            update(1, 1, tou[1], tin[i]);
            cout << i - 2 * msize << " ";
        }
        cout << "\n";
    }
}