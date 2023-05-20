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
        vector<int> a(n);
        int r = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == n)
                r = i;
        }
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        --r;
        if (r < 0) {
            for (int i = 0; i < n; i++)
                if (a[i] == n - 1)
                    r = i - 1;
        }
        vector<int> ans = vector<int> (n, 0);
        for (int l = 0; l <= r; l++) {
            vector<int> b;
            for (int j = r+1; j < n; j++)
                b.push_back(a[j]);
            FOD(j, r, l)
                b.push_back(a[j]);
            FOR(j, 0, l - 1)
                b.push_back(a[j]);
            FOr(j, 0, n)
                if (b[j] != ans[j]) {
                    if (b[j] > ans[j])
                        ans = b;
                    break;
                }
        }
        if (r == n - 2) {
            r = n - 1;
            for (int l = 0; l <= r; l++) {
                vector<int> b;
                for (int j = r+1; j < n; j++)
                    b.push_back(a[j]);
                FOD(j, r, l)
                    b.push_back(a[j]);
                FOR(j, 0, l - 1)
                    b.push_back(a[j]);
                FOr(j, 0, n)
                    if (b[j] != ans[j]) {
                        if (b[j] > ans[j])
                            ans = b;
                        break;
                    }
            }
        }
        FOr(i, 0, n)
            cout << ans[i] << " ";
        cout << "\n";

    }
}