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

const int N=(int)500+7;
const int MOD=998244353;
const ll INF=(ll)1e18+7;
int n,a[N];
int f[N][N];
int ans;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n) {
        char ch;
        cin >> ch;
        if (ch=='+')
            cin >> a[i];
    }
    f[0][1]=1;
    FOR(i,1,n) if (a[i]) {
        FOR(j,1,n)
            FOR(k,1,n)
                f[j][k]=0;

        FOR(j,1,i-1)
            FOR(k,1,n) {
                if (a[j]==0) {
                    f[j][k]=(f[j-1][k+1]+f[j-1][k])%MOD;
                    if (k==1)
                        f[j][k]+=f[j-1][k];
                }
                else {
                    if (a[j]<=a[i])
                        f[j][k]=f[j-1][k]+f[j-1][k-1];
                    else
                        f[j][k]=f[j-1][k]*2;
                }
                f[j][k]%=MOD;
            }

        FOR(j,1,n)
            f[i][j]=f[i-1][j];

        FOR(j,i+1,n)
            FOR(k,1,n) {
                if (a[j]==0)
                    f[j][k]=f[j-1][k+1]+f[j-1][k];
                else {
                    if (a[j]<a[i])
                        f[j][k]=f[j-1][k]+f[j-1][k-1];
                    else
                        f[j][k]=f[j-1][k]*2;

                }
                f[j][k]%=MOD;
            }
        int num=0;
        FOR(j,1,n)
            num=(num+f[n][j])%MOD;
        ans+=(1LL*num*a[i]%MOD);
        ans%=MOD;
    }
    cout << ans;
}
