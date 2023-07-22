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

const int N=2e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int IT[N];
void update(int i, int L, int R, int l, int r, int val) {
    if (l > R || r < L)
        return;
    if (l <= L && r >= R)  {
        IT[i] = val;
        return;
    }
    update(i * 2, L, (L + R) / 2, l, r, val);
    update(i * 2 + 1, (L + R) / 2 + 1, R, l, r, val);
}

int get(int i, int L, int R, int pos) {
    if (L == R)
        return IT[i];
    int M = (L + R) >> 1;
    if (pos <= M)
        return min(IT[i], get(i * 2, L, M, pos));
    return min(IT[i], get(i * 2 + 1, M + 1, R, pos));
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, m; 
    cin >> n >> m;
    vector<iii> a;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back({{x, y}, z});
    }

    FOR(i, 1, 4*n)
        IT[i] = MOD;

    FOD(i, m - 1, 0) {
        update(1, 1, n, a[i].F.F, a[i].S - 1, i);
        update(1, 1, n, a[i].S + 1, a[i].F.S, i);
    }
    // FOR(i, 1, 2*n)
    //     cout << IT[i] << " ";
    FOR(i, 1, n)
    if (i != a.back().S)
        cout << a[get(1, 1, n, i)].S << " ";
    else 
        cout << "0 ";
}