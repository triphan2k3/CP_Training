#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=4e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int dp[N],f[N];
int n,m;
int add(int a,int b) {
    a+=b;
    if (a<0)
        a+=m;
    if (a>=m)
        a-=m;
    return a;
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> m;
    int S = 1;
    FOR(i,1,n) {
        f[i]=add(f[i-1],f[i]);
        dp[i]=add(S,f[i]);//,dp[i-1]));
        for (int j=2; j*i <= n; j++) {
            f[i*j]=add(f[i * j], dp[i]);
            if ((i+1)*j <= n)
            f[(i+1)*j]=add(f[(i+1)*j],-dp[i]);
        }
        if (i>1) S=add(S,dp[i]);
        //cout<<dp[i] << "\n";
    }
    cout << dp[n];
}
