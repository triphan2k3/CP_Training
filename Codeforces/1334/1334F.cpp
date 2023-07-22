#include <bits/stdc++.h>
#define TASK "1334F"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=1; i>b ; i--)
using namespace std;
const int N=500009;
const ll MAX=(ll)1e16;
ll dp[N];
int a[N], b[N], p[N], r[N];
int n,m;
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];
    FOR(i, 1, n)
        cin >> p[i];
    cin >> m;
    FOR(i, 1, m) {
        cin >> b[i];
        r[b[i]] = i;
    }
    b[m+1] = n+1;
    r[n+1] = m+1;
    a[n+1] = n+1;
    FOD(i, n + 1, 1)
        r[i] = r[i] ? r[i] : r[i+1];

    dp[0] = -2*MAX;
    dp[m+1] = 2*MAX;
    FOR(i, 0, n+1) {
        int j=r[a[i]];
        if (a[i] == b[j] && dp[j] < min(0,p[i]) && j <= m) {
            dp[j+1] += dp[j];
            dp[j] = p[i];
            if (p[i] <= 0) {
                dp[m+1] += p[i];
                dp[j+1] -= p[i];
            }
        } else dp[p[i] < 0 ? m+1:j] += p[i];
    }
    if (dp[m+1] < MAX)
    cout << "YES\n" << dp[m+1];
    else cout<< "NO";
}
