#include <bits/stdc++.h>
#define TASK "1452D"
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
const ll MOD=998244353;
const ll INF=(ll)1e18+7;

ll pow(ll a, ll b) {
    if (b==1)
        return a;
    ll cnt=pow(a,b>>1);
    cnt=cnt*cnt % MOD;
    if (b%2)
        cnt=cnt*a % MOD;
    return cnt;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll prec=1,prel=0,ans=1;
    FOR(i,1,n) {
        if (i%2) {
            ans=prec;
            prel+=ans;
            prel%=MOD;
        } else
        {
            ans=prel;
            prec+=ans;
            prec%=MOD;
        }
    }
    ll cnt=1;
    FOR(i,1,n)
        cnt=(cnt+cnt) % MOD;

    cnt=pow(cnt,MOD-2);
    cout << ans*cnt%MOD;
}
