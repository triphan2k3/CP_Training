#include <bits/stdc++.h>
#define TASK "295D"
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
const ll MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll dp[2002][2002];

ll add(ll a, ll b) {
    a+=b;
    return a>MOD ? a-MOD : a;
}

ll mul(ll a,ll b) {
    return a*b % MOD;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;

    ll ans=0;

    FOR(i,2,m)
        dp[1][i]=1;
    FOR(i,1,n)
        dp[i][1]=1;
    FOR(i,2,n) {
        ll cur = 0;
        FOR(j,2,m) {
            cur=add(cur,dp[i-1][j]);
            dp[i][j]=add(dp[i][j-1],cur);
        }
    }

    FOR(i,1,n)
        FOR(j,2,m)
            ans=add(ans,
                mul(m-j+1,
                mul(dp[n-i+1][j],dp[i][j]-dp[i-1][j]+MOD)));


    cout << ans;
}
