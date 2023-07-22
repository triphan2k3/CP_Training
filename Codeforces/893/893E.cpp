#include <bits/stdc++.h>
#define TASK ""
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
int x,y;
int p[N];
int dp[N][21];
void sang() {
    int nmax=1000000;
    for(int i=2;i*i<=nmax;i++)
    if (!p[i]) {
        p[i]=i;
        for(int j=i*i;j<=nmax;j+=i)
            p[j]=i;
    }
    FOR(i,2,nmax)
    if (!p[i])
        p[i]=i;
}

void calldp() {
    int nmax=1000000;
    dp[0][0]=1;
    FOR(i,1,nmax) {
        dp[i][0]=1;
        FOR(j,1,20) {
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
            if (dp[i][j]>=MOD)
                dp[i][j]-=MOD;
        }
    }
}

int pow(int a,int b) {
    if (b==0)
        return 1;
    if (b==1)
        return a;
    int tmp=pow(a,b/2);
    tmp=(1LL*tmp*tmp) % MOD;
    if (b%2)
        tmp=(1LL*tmp*a) % MOD;
    return tmp;
}

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    calldp();
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        int ans=pow(2,y-1);
        while (x>1) {
            int uoc=p[x];
            int cnt=0;
            while (x%uoc == 0) {
                x/=uoc;
                cnt++;
            }
            ans=1LL*ans*dp[y][cnt] % MOD;
        }
        cout << ans << "\n";
    }
}
