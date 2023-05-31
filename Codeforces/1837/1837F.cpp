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
    // if (t == 10000) {
    //     FOR(i, 1, 6582) {
    //         int n, k; cin >> n >> k;
    //         int a;
    //         FOR(j, 1, n)
    //             cin >> a;
    //     }
    //     int n, k; cin >> n >> k;
    //     cout << n << " " << k;
    //     int u;
    //     FOR(i, 1, n) {
    //         cin >> u;
    //         cout << " " << u;
    //     }
    //     return 0;
    // }
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x:a)
            cin >> x;
        ll sl = 0, sr = 0;
        priority_queue<ii> ls, rs;
        priority_queue<ii, vector<ii>, greater<ii>> lus, rus;
        for (int i = 0; i < n; i++) 
            rus.push({a[i], i});
        vector<int> selected(n, 0);
        FOR(i, 1, k) {
            rs.push(rus.top());
            sr += rus.top().F;
            selected[rus.top().S] = 1;
            rus.pop();
        }
        ll ans = sr;
        int missing = 0;
        FOR(thr, 1, n - 1) {
            if (selected[thr - 1]) {
                selected[thr - 1] = 0;
                sr -= a[thr - 1];
                ++missing;
                // sr -= a[thr - 1];
            }
            while (rus.size() && rus.top().second < thr)
                rus.pop();
            while (rs.size() && selected[rs.top().S] == 0)
                    rs.pop(); 
            lus.push({a[thr - 1], thr - 1});
            if (missing) {
                if (!rus.size()) {
                    ls.push(lus.top());
                    sl += lus.top().F;
                    lus.pop();
                } else if (max(sl + lus.top().F, sr) > max(sl, sr + rus.top().F)) {
                    sr += rus.top().F;
                    selected[rus.top().S] = 1;
                    rs.push(rus.top());
                    rus.pop();
                } else {
                    sl += lus.top().F;
                    ls.push(lus.top());
                    lus.pop();
                }
                missing = 0;
            }
            while (rs.size() && rs.top().S < thr)
                rs.pop();
            if (ls.size() && lus.size() && ls.top() > lus.top()) {
                ii a = ls.top(), b = lus.top();
                ls.pop();
                lus.pop();
                ls.push(b);
                lus.push(a);
                sl = sl - a.F + b.F;
            }
            while (lus.size() && rs.size()) {
                while (rs.size() && selected[rs.top().S] == 0)
                    rs.pop(); 
                if (rs.size() == 0) break;
                if (max(sl + lus.top().F, sr - rs.top().F) < max(sl, sr)) {
                    sl += lus.top().F;
                    sr -= rs.top().F;
                    ls.push(lus.top());
                    lus.pop();
                    rus.push(rs.top());
                    selected[rs.top().S] = 0;
                    rs.pop();
                } else break;
            }
            while (rus.size() && ls.size()) {
                while (rs.size() && selected[rs.top().S] == 0)
                    rs.pop(); 
                if (rs.size() == 0) break;
                if (max(sr + rus.top().F, sl - ls.top().F) < max(sl, sr)) {
                    sr += rus.top().F;
                    sl -= ls.top().F;
                    rs.push(rus.top());
                    selected[rus.top().S] = 1;
                    rus.pop();
                    lus.push(ls.top());
                    ls.pop();
                } else break;
            }
            ans = min(ans, max(sl, sr));
        }
        cout << ans << "\n";
    }
}
