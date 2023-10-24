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

vector<int> v2;
int a[N];
int n;



int call(int l, int r) {
    if (r - l <= 1) return 0;
    int next2 = *(lower_bound(all(v2), l + 1));
    if (next2 < r) {
        int newR = next2;
        while (a[newR] != 0) --newR;
        int newL = next2;
        while (a[newL] != 0) ++newL;
        return 1 + call(l, newR) + call(newL, r);
    }
    // 2 not exists
    if (a[l + 1] == 1) {
        ++l;
        while (a[l] == 1)
            ++l;
        return 1 + call(l, r);
    }
    if (a[r - 1] == 1) {
        --r;
        while (a[r] == 1)
            --r;
        return 1 + call(l, r);
    }
    ++l;
    --r;
    int ans = r - l + 1;
    FOR(i, l, r)
        ans -= a[i];
    return ans;
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        if (a[i] == 2)
            v2.pb(i);
    }
    v2.pb(n + 1);
    cout << call(0, n + 1) << "\n";
}