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
ii a[N];
ll cost(ii a,ii b) {
    int d1=a.F-a.S;
    int d2=b.F-b.S;
    if (d1==d2 && d1%2==0)
        return b.F-a.F;
    if (d1%2==0)
        d1++;
    if (d2%2==0)
        d2++;
    return (d2-d1)>>1;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n)
            cin >> a[i].F;
        FOR(i,1,n)
            cin >> a[i].S;
        sort(a+1,a+n+1);
        ll ans=0;
        a[0]={1,1};
        FOR(i,1,n)
            ans+=cost(a[i-1],a[i]);
        cout << ans << "\n";
    }
}
