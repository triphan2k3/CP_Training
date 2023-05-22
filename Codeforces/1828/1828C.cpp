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
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x:a) cin >> x;
        for (int &y:b) cin >> y;
        sort(all(a));
        sort(all(b));
        int ans = 1;
        int flag = 1;
        FOr(i, 0, n)
            if (a[i] <= b[i]) {
                flag = 0;
                break;
            }
        if (!flag) {
            cout << "0\n";
            continue;
        }
        vector<int> c(n + 1);
        FOr(i, 0, n) {
            int maxJ = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            c[i + 1] = maxJ;
        }
        // for (int x:a) cout << x << " "; cout << endl;
        // for (int x:b) cout << x << " "; cout << endl;
        // FOR(i, 1, n) cout << c[i] << " "; cout << endl << endl;
        FOR(i, 1, n)
            ans = 1LL * ans * (c[i] - i + 1) % MOD;
        cout << ans << '\n';
    }
}