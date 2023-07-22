#include <bits/stdc++.h>
#define TASK "1345F"
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
ll n, k, all;
ll a[N],res[N];
ll Get(ll a, ll x) {
    return a-3LL*x*(x-1LL)-1LL;
}

int check(ll x) {
    ll sum=0;
    FOR(i, 1, n) {
        ll l=0,r=a[i];
        res[i] = 0;
        while (l<=r) {
            ll m=(l+r)>>1;
            if (Get(a[i],m) >= x) {
                res[i]=m;
                l = m+1;
            } else
                r = m-1;
        }
        sum += res[i];
    }
    all=sum;
    return sum<=k;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    FOR(i, 1, n)
        cin >> a[i];
    ll l=-3e18, r=1e9;
    ll ans=l;
    while (l<=r) {
        ll m=(l+r) >> 1;
        if (check(m)) {
            ans=m;
            r = m-1;
        }
        else l = m+1;
    }
    check(ans);
    k-=all;
    FOR(i, 1, n)
        if (k && res[i]<a[i] && Get(a[i],res[i]+1)==ans-1)
            res[i]++,k--;
    FOR(i, 1, n)
        cout << res[i] << " ";
}
