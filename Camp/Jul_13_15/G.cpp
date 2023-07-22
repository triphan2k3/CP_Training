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
    int n;
    cin >> n;
    vector<int> a(5, 0);
    int sum = 0;
    FOR(i, 1, n) {
        int x; cin >> x;
        a[x]++;
        sum += x;
    }
    if (sum < 3 || sum == 5) {
        cout << -1;
        return 0;
    }

    if (a[2] == 0 && a[1] == 0) {
        cout << 0;
        return 0;
    }
    
    int ans = MOD;
    FOR(n3, 0, sum / 3) {
        int n4 = sum - 3*n3;
        if (n4 % 4) continue;
        n4 /= 4;
        vector<int> t = a;
        if (t[4] > n4) {
            t[1] += t[4] - n4;
            t[3] += t[4] - n4;
            t[4] = n4;
        }
        int g2 = min(t[2], n3 + n4 - t[4] - t[3]);
        int g1 = n3 + n4 - t[4] - t[3] - g2;
        ans = min(ans, sum - t[4] * 4 - t[3] * 3 - g2 * 2 - g1);
        // int f = t[4] * 4 + max(0, min3 + n4 - t[4])

    }
    cout << ans;
    return 0;
}