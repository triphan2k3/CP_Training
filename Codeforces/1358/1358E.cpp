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
ll a[N],pre[N];
int n;
ll x,Pre;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int nn=(n+1)>>1;
    FOR(i,1,nn) {
        cin >> a[i];
        Pre+=a[i];
    }
    cin >> x;

    FOR(i,1,nn)
        pre[i]=pre[i-1]+x-a[i];
    FOR(i,1,nn)
        pre[i]=min(pre[i-1],pre[i]);
    int ans=-1;

    FOR(k,nn,n)
        if (Pre+pre[n-k]>0) {
            ans=k;
            break;
        } else Pre+=x;
    cout << ans << "\n";
}



