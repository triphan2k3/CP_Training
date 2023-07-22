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
vector<int> a[N];

long long numSeg(int n) {
    return 1LL * n * n;
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
    FOR(i, 1, n) {
        int x; cin >> x;
        a[x].push_back(i);
    }
    long long ans = 0;
    FOR(i, 1, 1000000) if (a[i].size()) {
        sort(all(a[i]));
        long long haveI = 1LL * n * n - numSeg(a[i][0] - 1) - numSeg(n - a[i].back());
        FOR(j, 1, a[i].size() - 1)
            haveI -= numSeg(a[i][j] - a[i][j - 1] - 1);
        ans += haveI;
    }

    cout << setprecision(4) << fixed << (double)ans / n / n;
}