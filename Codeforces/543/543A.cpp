#include <bits/stdc++.h>
#define TASK "543A"
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

const int N=(int)500+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[2][N][N];
int a[N];
int n,m,b,mod;

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> b >> mod;
    FOR(i,1,n)
        cin >> a[i];
    f[0][0][0]=1;
    FOR(i,1,n) {
        f[i&1][0][0]=1;
        FOR(j,1,m)
        FOR(k,0,b) //DEN NGUOI THU I DA VIET DC J DONG VA CO K BUG
            {
                f[i&1][j][k]=f[(i+1)&1][j][k];
                if (a[i] <= k)
                    f[i&1][j][k]+=f[i&1][j-1][k-a[i]];
                f[i&1][j][k]%=mod;
            }
    }
    int ans=0;

    FOR(k,0,b)
        ans=(ans+f[n&1][m][k]) % mod;

    cout << ans;
}
