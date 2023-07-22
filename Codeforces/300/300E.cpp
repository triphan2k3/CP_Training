#include <bits/stdc++.h>
#define TASK "300E"
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

const int N=(int)1e7+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll a[N],nt[N];
vector<ll> p;
int k;

void sang() {
    for (int i=2;i*i<=(int) 1e7;i++)
        if (!nt[i]) {
        for (int j=i*i;j<=(int) 1e7;j+=i)
            nt[j]=i;
    }
    FOR(i,2,(int) 1e7)
        if (!nt[i]) {
            nt[i]=i;
            p.push_back(i);
        }
    return;
}

void chuyen() {
    for (int i=(int)1e7;i>=2;i--)
        if (nt[i]!=i) {
            a[  nt[i]]+=a[i];
            a[i/nt[i]]+=a[i];
            a[i]=0;
        }
}

int check(ll n) {
    for (int i:p) {
        ll sum=0;
        for(ll j=i;j<=n;j*=i)
            sum+=n/j;
        if (sum<a[i])
            return 0;
    }
    return 1;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    FOR(i,1,k) {
        int x;
        cin >> x;
        a[x+1]--;
    }
    a[1]+=k;
    FOR(i,1,(int)1e7)
        a[i]+=a[i-1];

    sang();
    chuyen();
    ll l=1, r=(ll)1e14;
    ll ans=r;
    while (l<=r) {
        ll mid=(l+r) >> 1;
        if (check(mid)) {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
}
