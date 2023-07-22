#include <bits/stdc++.h>
#define TASK "bonus"
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
ll dp[303][303][153];
ll a[303];

ll calc(int l,int r,int rem) {
    if (rem==0 )
        return dp[l][r][rem] = 0;
    if (r-l+1 < rem*2)
        return - INF;
    if (dp[l][r][rem]!=-1)
        return dp[l][r][rem];
    ll ret1 = calc(l+2,r,rem-1)  + abs(a[l]-a[l+1]);
    ll ret2 = calc(l,r-2,rem-1)  + abs(a[r]-a[r-1]);
    ll ret3 = calc(l+1,r-1,rem-1)+ abs(a[l]-a[r]);
    ll ret4 = max(calc(l+1,r,rem),calc(l,r-1,rem));
    return dp[l][r][rem] = max( max(ret1,ret2), max(ret3,ret4) );
}
int main() {
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        FOR(j,1,n)
            FOR(p,0,k)
                dp[i][j][p]=-1;
    cout << calc(1,n,k);
}
