#include <bits/stdc++.h>
#define TASK "1146F"
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
const ll MOD=998244353 ;
const ll INF=(ll)1e18+7;

ll dp[N][3];
vector<int> a[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    FOR(i,2,n) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    FOD(u,n,1) {
        if (a[u].size()==0) {
            dp[u][2]=1;
            continue;
        }
        dp[u][0]=1;

        for (int v:a[u]) {
            dp[u][2]= (dp[u][2]*(dp[v][1]+2LL*dp[v][2]+dp[v][0]) % MOD + dp[u][1]*(dp[v][1]+dp[v][2]) % MOD) % MOD;

            dp[u][1]= (dp[u][1]*(dp[v][0]+dp[v][2]) % MOD + dp[u][0] * (dp[v][1] + dp[v][2]) % MOD) % MOD;

            dp[u][0]= dp[u][0] * ( dp[v][0] + dp[v][2] ) % MOD;
        }
    }
    cout << (dp[1][0] + dp[1][2] ) % MOD;


}
