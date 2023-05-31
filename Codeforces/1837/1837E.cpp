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
const int MOD=998244353;
const ll INF=(ll)1e18+7;
int lt[N], gt[N];

void prepare() {
    lt[0] = gt[0] = 1;
    FOR(i, 1, N - 1) {
        lt[i] = 2 * lt[i - 1] % MOD;
        gt[i] = gt[i - 1] * 1LL * i % MOD;
    }
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    prepare();
    int t = 1;// cin >> t;
    while (t--) {
        int k; cin >> k;
        int n = 1 << k;
        vector<int> pos(n, -1);
        FOr(i, 0, n) {
            cin >> pos[i];
            if (pos[i] > -1) {
                --pos[i];
            }
        }
        int ans = 1;
        int flag = 1;
        FOR(r, 1, k) {
            int cnt = 0;
            int pw = 0;
            FOr(i, 0, 1 << (k - r)) {
                int c1 = pos[i * 2];
                int c2 = pos[i * 2 + 1];
                if (c1 == c2) {
                    pos[i] = -1;
                    ++cnt;
                    ++pw;
                } else {
                    if (c1 > c2) swap(c1, c2);
                    if (c1 == -1) {
                        if (c2 >= (1 << (k - r))) {
                            pos[i] = -1;
                        } else {
                            ++cnt;
                            pos[i] = c2;
                        }
                    } else {
                        if (c1 >= (1 << (k - r)) || c2 < (1 << (k - r))) {
                            flag = 0;
                            break;
                        } else {
                            pos[i] = c1;
                        }
                    }
                }
            }
            if (!flag) break;
            int aans = 1LL * lt[pw] * gt[cnt] % MOD;
            ans = ans * 1LL * aans % MOD;
        }
        if (flag)
            cout << ans << "\n";
        else 
            cout << "0\n";
    }
}