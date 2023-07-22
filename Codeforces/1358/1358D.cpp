#include <bits/stdc++.h>
#define TASK "1358D"
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

const int N=(int)2e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll n, x;
ll v[N],d[N];
ll nhan(ll a, ll b) {
    return (b+a)*(b-a+1LL)/2LL;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    FOR(i,1,n)
        cin >> d[i];
    FOR(i,n+1,n+n)
        d[i]=d[i-n];
    n+=n;
    FOR(i,1,n)
        v[i]=(d[i]*(d[i]+1LL)) / 2LL;

    ll l=n+1;
    ll cost=0;
    ll rc=0;
    ll ans=0;
    FOD(r,n,1) {
        if (d[r]>=x) {
            ans=max(ans,nhan(d[r]-x+1LL,d[r]));
            continue;
        }
        cost-=d[r+1];
        rc-=v[r+1];
        if (l>r) {
            l=r;
            cost=d[r];
            rc=v[r];
        }
        while (l>=2 && cost+d[l-1]<=x) {
            cost+=d[--l];
            rc+=v[l];
        }
        ans=max(ans,rc);
        if (l==1) continue;
        ll cl=x-cost;
        ans=max(ans,rc+nhan(d[l-1]-cl+1LL,d[l-1]));
    }
    cout << ans;
}
