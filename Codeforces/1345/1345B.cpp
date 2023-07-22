#include <bits/stdc++.h>
#define TASK "1345B"
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
const int LAST=25820;
const ll INF=(ll)1e18+7;
int dp[N];

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1]=2; int li=1;
    FOr(i,2,LAST)
        dp[i]=dp[i-1]+(i-1)+2*i;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans=0;
        while (n>1) {
            int pos=upper_bound(dp+1,dp+LAST,n)-dp-1;
            n-=dp[pos];
            ans++;
        }
        cout << ans << "\n";
    }
}
