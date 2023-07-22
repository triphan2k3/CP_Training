#include <bits/stdc++.h>
#define TASK "484D"
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
ll a[N],dp[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];

    dp[2]=abs(a[2]-a[1]);
    int state=a[2]>=a[1] ? 1:-1;
    int preid=1;
    FOR(i,3,n) {
        int nstate=a[i]>=a[i-1] ? 1:-1;
        if (nstate!=state) {
            state=nstate;
            preid=i-1;
        }
        dp[i]=dp[i-1];
        dp[i]=max(dp[i],dp[preid-1]+abs(a[preid]-a[i]));
        dp[i]=max(dp[i],dp[preid]+abs(a[preid+1]-a[i]));
    }
    cout << dp[n];
}
