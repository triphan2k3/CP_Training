#include <bits/stdc++.h>
#define TASK "1348E"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ii> a(n+1);
    vector<int> f(k+1,0);
    f[0] = 1;
    ll sum=0;
    FOR(i, 1, n)  {
        cin >> a[i].F >> a[i].S;
        sum += a[i].F + a[i].S;
    }

    FOR(i, 1, n) {
        vector<int> g(k+1,0);
        int Si = a[i].S % k;
        FOr(j, 0, k)
            g[j] = f[(j-Si+k)%k];

        FOr(j,1,k) {
            if (a[i].S < j || a[i].F < k-j) continue;
            int remain = (a[i].S - j) % k;
            FOR(u,0,k)
                if (f[u]) g[(u+remain)%k] = 1;
        }
        f=g;
    }
    ll ok=-1;
    FOr(i, 0, k) if (f[i]) {
            ok=i;
            break;
    }
    ll ans = (sum-ok)/k;
    cout << ans;
    return 0;
}
