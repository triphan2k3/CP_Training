#include <bits/stdc++.h>
#define TASK "1328F"
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

const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll a[N],s[N];
int n,k;

ll sum(int l,int r) {
    return s[r]-s[l-1];
}

ll proc(int l,int r) {
    int rem=k-(r-l+1);
    if (rem<=0) return 0;

    ll lef= l!=1 ? (a[l]-1)*(l-1)-sum(1,l-1):0;
    ll rig= r!=n ? sum(r+1,n)-(a[r]+1)*(n-r):0;

    ll afterL=k-r;
    ll afterR=k-(n-l+1);

    ll ans1=1LL*min(rem,l-1) + lef;
    if (afterL > 0)
        ans1+=rig+afterL;

    ll ans2=1LL*min(rem,n-r) + rig;
    if (afterR > 0)
        ans2+=lef+afterR;

    return min(ans1,ans2);
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i];
    sort(a+1,a+n+1);

    FOR(i,1,n)
        s[i]=s[i-1]+a[i];

    ll ans=INF;
    for(int l=1;l<=n;) {
        int r=l;
        while (a[r+1]==a[l] && r<n)
            r++;
        ans=min(ans,proc(l,r));
        l=r+1;
    }
    cout << ans;
}
