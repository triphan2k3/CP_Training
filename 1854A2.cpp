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

int query(int small, int big) {
    int ret = 0;
    while (small < big) {
        small *= 2;
        ret++;
    }
    return ret;
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
        int n;
        cin >> n;
        vector<int> a(n);
        int mi = 100, ma = -100;
        int idmi, idma;
        int c = 0;
        int numpos = 0;
        int numneg = 0;
        for (int &x:a) {
            cin >> x;
            if (x < mi) {
                mi = x;
                idmi = c;
            }
            if (x > ma) {
                ma = x;
                idma = c;
            }
            if (x > 0)
                ++numpos;
            if (x < 0)
                ++numneg;
            c++;
        }

        if (mi >= 0) {
            cout << n - 1 << '\n';
            for (int i = 2; i <= n; i++)
                cout << i << " " << i - 1 << "\n";
        } else if (ma <= 0) {
            cout << n - 1 << '\n';
            for (int i = n - 1; i >= 1; i--)
                cout << i << " " << i + 1 << "\n";
        } 
        else {
            int movePostoNeg = numpos + query(abs(mi), ma);
            int moveNegtoPos = numneg + query(ma, abs(mi));
            vector<ii> ans;
            if (movePostoNeg <= 12) {
                while (abs(mi) < ma) {
                    ans.push_back({idmi, idmi});
                    mi *= 2;
                }
                for (int i = 0; i < n; i++)
                    if (a[i] > 0) // pos
                        ans.push_back({i, idmi});
                for (int i = n - 2; i >= 0; i--)
                    ans.pb({i, i+1});
            } else {
                while (ma < abs(mi)) {
                    ans.pb({idma, idma});
                    ma *= 2;
                }
                for (int i = 0; i < n; i++)
                    if (a[i] < 0)
                        ans.pb({i, idma});
                for (int i = 1; i < n; i++)
                    ans.pb({i, i - 1});
            }
            cout << ans.size() << "\n";
            for (ii x:ans)
                cout << x.F + 1 << " " << x.S + 1 << "\n";
        }
    }
}