#include <bits/stdc++.h>
#define TASK "1380D"
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

const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll m,n,x,k,y;
ll a[N],b[N],trace[N],dp[N],vt[N];
bool check() {
    int pos=1;
    FOR(i,1,m) {
        while (a[pos]!=b[i] && pos<=n) pos++;
        if (pos>n) return 0;
        trace[i]=pos;
        pos++;
    }

    trace[++m]=n+1;
    for (int i=1;i<=m;i++)
        if (trace[i]-trace[i-1]-1 < k) {
            ll ma=max(b[i-1],b[i]);
            for (int j=trace[i-1];j<=trace[i];j++)
                if (a[j]>ma) return 0;
    }
    for (int i=1;i<=m;i++)
        if (trace[i]-trace[i-1]-1 >= k) {
            int kt=0;
            ll ma=max(b[i-1],b[i]);
            for (int j=trace[i-1];j<=trace[i];j++)
                if (a[j]>ma) kt=1;
            vt[i]=kt;
        }

    return 1;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> k >> y;
    FOR(i,1,n)
        cin >> a[i];

    FOR(i,1,m)
        cin >> b[i];
    if (!check()) {
        cout << -1;
        return 0;
    }
    ll ux=x;
    x=min(x,y*k);
    ll ans=0;
    for (int i=1;i<=m;i++) {
        ll numdel=trace[i]-trace[i-1]-1;
        if (vt[i]) {
            numdel-=k;
            ans+=ux;
        }
        ll numx=numdel/k;
        ll numy=numdel%k;
        ans+=x*numx+y*numy;
    }

    cout << ans;
}
