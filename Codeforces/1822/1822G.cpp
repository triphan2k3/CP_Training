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

const int N=1000000+7;
const int MOD=1000000000+7;
const ll INF=(ll)1e18+7;
vector<int> d[N];

void prepare() {
    FOR(i, 2, 1e6) 
        FOR(j, 1, 1e6/i)
            if (i * j * 1LL * i <= 1000000000)
                d[i*j].push_back(i);
}

int cnt(int val, vector<int> &a) {
    return upper_bound(a.begin(), a.end(), val) - lower_bound(a.begin(), a.end(), val);
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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        FOr(i, 0, n) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> A = a;
        ll ans = 0;
        a.resize(distance(a.begin(), unique(a.begin(), a.end())));
        for(auto val:a) {
            int num = cnt(val, A);
            ans += 1LL * num * (num - 1) * (num - 2);
        }
        FOr(j, 1, a.size()) {
            if (a[j] > 1000000) {
                FOR(b, 2, 1000000000 / a[j]) if (a[j] % b == 0)
                    ans += 1LL * cnt(a[j], A) * cnt(a[j] * b, A) * cnt(a[j] / b, A);
            } else {
                for(int b:d[a[j]]) {
                    ans += cnt(a[j], A) * 1LL * cnt(a[j] * b, A) * cnt(a[j] / b, A);
                }
            }
        }
        cout << ans << "\n";
    }
}