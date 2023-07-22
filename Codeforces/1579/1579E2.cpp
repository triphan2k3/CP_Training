#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
ii a[N];
int b[N],BIT[N];
int n;

int get(int x) {
    int ans = 0;
    for(;x>0;x -= x&(-x))
        ans += BIT[x];
    return ans;
}

void update(int x) {
    for(;x<=n;x += x&(-x))
        BIT[x]++;
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,1,n) { 
            cin >> a[i].F;
            a[i].S = i;
        }
        sort(a+1,a+n+1);
        map<int,int> mp;
        FOR(i,1,n) 
            mp[a[i].F] = i;
        FOR(i,1,n)
            b[a[i].S] = mp[a[i].F];
        FOR(i,1,n) BIT[i] = 0;
        ll ans = 0;
        FOR(i,1,n) {
            ans += 1LL*min(get(b[i]-1),get(n)-get(b[i]));
            update(b[i]);
        }
        cout << ans << "\n";
    }
}