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

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t; cin >> t;
    ii cnt[40];
    cnt[0] = {1, 0};
    cnt[1] = {0, 1};
    FOR(i, 2, 33)
        cnt[i] = {cnt[i - 1].F + cnt[i - 2].F, cnt[i - 1].S + cnt[i - 2].S};
    while (t--) {
        int n, k;
        cin >> n >> k;
        // ax + by = n
        if (k > 31) {
            cout << "0\n";
            continue;
        }
        int a = cnt[k - 1].F;
        int b = cnt[k - 1].S;
        // cout << a << " " << b << " ";
        // want: a < b;
        int ans = 0;
        for (int x = 0; a * x <= n; x++) {
            int y = (n - a * x) / b;
            if (x <= y && a*x + b * y == n)
            ++ans;
        }
        cout << ans << "\n";
    }
}