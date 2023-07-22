#include <bits/stdc++.h>
#define TASK "1453B"
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
ll a[N],f[N],pre[N];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];
        f[n]=0;
        FOD(i,n-1,1)
            f[i]=abs(a[i]-a[i+1]);

        FOR(i,1,n)
            pre[i]=pre[i-1]+f[i];
        FOD(i,n-1,1)
            f[i]+=f[i+1];
        f[n+1]=0;
        ll ans=f[2];
        a[n+1]=a[n-1];
        FOR(i,2,n)
            ans=min(ans,f[i+1]+pre[i-2]+abs(a[i+1]-a[i-1]));
        cout << ans << "\n";

    }
}
