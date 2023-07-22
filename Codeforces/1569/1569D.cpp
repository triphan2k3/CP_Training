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
int x[N],y[N];
int n,m,k;
ll call(int st,int lst,int all) {
    int sz = lst-st+1;
    return 1LL*sz*(all-sz);
}

ll xuli(int cs) {
    int l = 1, r = 1;
    ll ans = 0;
    int lst = cs==1? n:m;
    FOR(i,2,lst) {
        int d = cs==1 ? x[i-1]+1 : y[i-1]+1;
        int u = cs==1 ? x[i]  -1 : y[i]  -1;
        while (r<=k && a[r].F<=u) ++r;
        --r;
        while (l<=k && a[l].F<d) ++l;
        if (r<l) continue;
        vector<int> v;
        FOR(j,l,r)
            v.pb(a[j].S);
        sort(v.begin(),v.end());
        int all = v.size();
        v.push_back(-1);
        int pre = 0;
        FOR(j,1,all) 
            if (v[j]!=v[j-1]) {
                ans+=1LL*call(pre,j-1,all);
                pre=j;
            }
    }
    return ans;
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
        cin >> n >> m >> k;
        FOR(i,1,n)
            cin >> x[i];
        FOR(i,1,m)
            cin >> y[i];
        FOR(i,1,k)
            cin >> a[i].F >> a[i].S;
        sort(a+1,a+k+1);
        sort(x+1,x+n+1);
        sort(y+1,y+m+1);
        ll ans = xuli(1);
        FOR(i,1,k)
            swap(a[i].F,a[i].S);
        sort(a+1,a+k+1);
        ans+=xuli(2);
        ans /= 2LL;
        cout << ans << '\n';
    }
}