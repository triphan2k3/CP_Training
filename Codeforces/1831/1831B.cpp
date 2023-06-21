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
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &x:a) cin >> x;
        for (int &x:b) cin >> x;
        vector<int> s1(n, 1), s2(n, 1);
        vector<int> cnt1(2 * n, 0), cnt2(2 * n, 0);
        cnt1[a[n - 1] - 1] = cnt2[b[n - 1] - 1] = 1;
        FOD(i, n - 2, 0) {
            if (a[i] == a[i + 1])
                s1[i] = s1[i + 1] + 1;
            if (b[i] == b[i + 1])
                s2[i] = s2[i + 1] + 1;
            cnt1[a[i] - 1] = max(cnt1[a[i] - 1], s1[i]);
            cnt2[b[i] - 1] = max(cnt2[b[i] - 1], s2[i]);
        }
        int ans = 1;
        FOR(i, 1, 2 * n)
            ans = max(ans, cnt1[i - 1] + cnt2[i - 1]);
        cout << ans << "\n";
    }
}