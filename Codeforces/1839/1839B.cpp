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

bool cmp(ii a, ii b) {
    return a.F != b.F ? a.F < b.F : a.S > b.S;
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
        vector<ii> a(n);
        for (ii &x:a) cin >> x.F >> x.S;
        sort(all(a), cmp);
        int curbr = 0;
        int num = 0;
        ll ans = 0;
        for (ii x:a) {
            int A = x.F;
            int B = x.S;
            if (A != curbr) {
                num = 1;
                curbr = A;
            } else 
                ++num;
            if (num <= curbr)
                ans += B;
        }
        cout << ans << "\n";
    }
}