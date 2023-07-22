#include <bits/stdc++.h>
#define TASK "1342E"
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
const int MOD=998244353;
const ll INF=(ll)1e18+7;
ll gt[N],_gt[N];
int n,k;

ll lt(ll a, int b) {
    if (b==1) return a;
    ll tmp=lt(a,b/2);
    tmp=tmp*tmp % MOD;
    if (b%2) tmp*=a;
    tmp%=MOD;
    return tmp;
}

ll C(int k, int n) {
    ll ans=gt[n]*_gt[k] % MOD;
    ans=ans*_gt[n-k]%MOD;
    return ans;
}
void add(ll &a, ll b) {
    a+=b;
    if (a>=MOD)
        a%=MOD;
    return;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (k>=n) {
        cout<<0;
        return 0;
    }
    gt[0]=1;
    FOR(i, 1, n)
        gt[i]=gt[i-1]*i % MOD;
    _gt[n]=lt(gt[n],MOD-2);
    FOD(i, n-1, 1)
        _gt[i]=_gt[i+1]*(i+1) % MOD;
    _gt[0]=_gt[1];
    if (k==0) {
        cout<<gt[n];
        return 0;
    }

    int c=n-k;
    ll ans=0;
    FOR(i, 0, c) {
        ll t=C(c-i,c)*lt(1LL*(c-i),n) % MOD;
        if (i%2)
            ans=ans+MOD-t;
        else ans+=t;
        ans%=MOD;
    }
    ans*=2;
    ans=ans * C(c,n) % MOD;
    cout<<ans;
    return 0;
}
