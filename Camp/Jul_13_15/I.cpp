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

int gr[N][26];
int cnt[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    ll n, m;
    string x, y;
    cin >> n >> m >> x >> y;
    ll d = __gcd(m, n);
    n /= d;
    m /= d;
    
    vector<int> used(N, 0);
    for (int i = 0, cnt = 0; i < x.size(); i++) if (used[i] == 0) {
        used[i] = ++cnt;
        for (int j = (i + y.size()) % x.size(); j != i; j = (j + y.size()) % x.size())
            used[j] = cnt;
    }
    for (int i = 0; i < x.size(); i++) {
        gr[used[i]][x[i] - 'a']++;
        cnt[used[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < y.size(); i++) {
        int id = used[i % x.size()];
        ans += cnt[id] - gr[id][y[i] - 'a'];
    }
    ans *= d;
    cout << ans;
}