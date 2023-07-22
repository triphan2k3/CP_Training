#include <bits/stdc++.h>
#define TASK "1359D"
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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],l[N],L[N],r[N],R[N];
int n;
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        L[i]=L[i-1]+a[i];
    FOD(i,n,1)
        R[i]=R[i+1]+a[i];

    FOR(i,1,n)
        l[i]=min(L[i],l[i-1]);

    FOD(i,n,1)
        r[i]=min(R[i],r[i+1]);

    int ans=max(R[2]-r[2],L[n-1]-l[n-1]);
    FOR(i,2,n-1)
        ans=max(ans,R[i+1]-r[i+1]+L[i-1]-l[i-1]);
    cout << ans;
}
