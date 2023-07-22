#include <bits/stdc++.h>
#define TASK "453B"
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

const int N=(int)132007;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int tt[61],a[101];
int dp[101][N],tc[101][N];
int n,cnt;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    FOR(i,2,60)
        if (tt[i]==0) {
            for (int j=i;j<=60;j+=i)
                tt[j]|=1<<cnt;
            cnt++;
        }

    cin >> n;
    FOR(i,1,n)
        cin >> a[i];

    FOR(i,1,n)
        FOR(j,0,1<<cnt)
            dp[i][j]=100000;

    FOR(i,1,n)
        FOr(mask,0,1<<cnt)
            FOR(j,1,60) {
                if (tt[j] & mask) continue;
                if (dp[i][mask | tt[j]] > dp[i-1][mask] + abs(a[i]-j)) {
                    dp[i][mask | tt[j]]=dp[i-1][mask] + abs(a[i]-j);
                    tc[i][mask | tt[j]]=j;
                }
            }
    int emask=0;
    FOr(mask,0,1<<cnt)
        if (dp[n][emask] > dp[n][mask])
            emask=mask;

    FOD(i,n,1) {
        a[i]=tc[i][emask];
        emask^=tt[a[i]];
    }
    FOR(i,1,n)
        cout << a[i] << " ";
}
