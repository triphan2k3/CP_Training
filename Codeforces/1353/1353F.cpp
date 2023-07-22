#include <bits/stdc++.h>
#define TASK "1353F"
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

const int N=(int)1e2+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ll dp[N][N],a[N][N];
int n,m;

ll Try(ll x) {
    dp[1][1]=a[1][1]-x;
    if (dp[1][1]<0) return -1;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) {
        if (i+j==2) continue;
        dp[i][j]=-1;
        ll a1=-1,a2=-1,val=x+i+j-2;

        if (a[i][j]<val) continue;
        if (dp[i-1][j]!=-1)
            a1=dp[i-1][j]+a[i][j]-val;

        if (dp[i][j-1]!=-1)
            a2=dp[i][j-1]+a[i][j]-val;

        if (a1==-1) dp[i][j]=a2;
        if (a2==-1) dp[i][j]=a1;
        if (a1!=-1 && a2!=-1)
            dp[i][j]=min(a1,a2);
    }
    return dp[n][m];
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=0;i<=100;i++)
        dp[0][i]=dp[i][0]=-1;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<ll> v;
        FOR(i,1,n)
            FOR(j,1,m) {
                cin >> a[i][j];
                v.push_back(a[i][j]-i-j+2);
            }
        ll ans=INF;
        for (ll i:v) {
            ll val=Try(i);
            if (val==-1) continue;
            ans=min(ans,val);
        }
        cout << ans << "\n";
    }
}
