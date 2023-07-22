#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int T, n;
ll a[N], gcd[N][18];
ll queryGcd(ll x, ll y)
{
    if (x == 0) return y;
    if (y == 0) return x;
    return __gcd(x, y);
}
ll query(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return queryGcd(gcd[l][k], gcd[r - (1 << k) + 1][k]);
}
int main()
{
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i], gcd[i][0] = 0;
        FOR(i, 1, 17) for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            gcd[j][i] = queryGcd(gcd[j][i - 1], gcd[j + (1 << (i - 1))][i - 1]);
            gcd[j][i] = queryGcd(gcd[j][i], abs(a[j + (1 << (i - 1))] - a[j - 1 + (1 << (i - 1))]));
        }
        int r = 1, ans = 0;
        FOR(l, 1, n)
        {
            while (r < n)
            {
                int tem = query(l, r + 1);
                if (tem == 0 || tem > 1) r++;
                else break;
            }
            // cout << l << ' ' << r << '\n';
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
}
