#include <bits/stdc++.h>
#define TASK "1341E"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;
const int M=10009;
const int G=1009;
int d[M][G];
int a[M];
int n, m, g, r;

int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, m)
        cin >> a[i];
    sort(a+1, a+m+1);
    cin >> g >> r;

    FOR(i, 1, m)
        if (a[i]-a[i-1] > g) {
            cout<<-1;
            return 0;
        }
    FOR(i, 1, m)
        FOR(j, 0, g-1)
            d[i][j] = 1e9;
    d[1][a[1]]=(a[1]==g) ? 1:0;
    deque<ii> q;
    q.pb({1,a[1]});
    while (q.size()) {
        int i = q.back().F;
        int j = q.back().S;
        q.pop_back();
        int cost = d[i][j];
        int tr = j + a[i+1] - a[i];
        int tl = j + a[i] - a[i-1];
        if (i < m && tr<=g) {
            if (tr == g) cost++;
            if (d[i+1][tr % g] > cost) {
                d[i+1][tr % g] = cost;
                if (cost > d[i][j])
                    q.push_front({i+1,tr % g});
                else
                    q.push_back({i+1,tr % g});
            }
        }
        cost = d[i][j];
        if (i > 1 && tl<=g) {
            if (tl == g) cost++;
            if (d[i-1][tl % g] > cost) {
                d[i-1][tl % g] = cost;
                if (cost > d[i][j])
                    q.push_front({i-1,tl % g});
                else
                    q.push_back({i-1,tl % g});
            }
        }
    }
    ll ans=(n > g) ? 1e15 : n ;
    if (a[m]==n) m--;
    FOR(i, 0, m)
        if (n - a[i] <= g && d[i][0] != 1e9)
            ans = min(ans, 1LL*d[i][0]*(g + r) + n - a[i]);
    if (ans == 1e15) cout<<-1;
    else
        cout << ans;
}
