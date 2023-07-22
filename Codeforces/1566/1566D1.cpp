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

const int N=300+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
ii a[N];
int valid[N],seat[N];

bool cmp(ii a,ii b) {
    return a.F != b.F ? a.F < b.F : a.S > b.S;
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
        int n,m;
        cin >> n >> m;
        FOR(i,1,m) {
            cin >> a[i].F;
            a[i].S = i;
        }
        sort(a+1,a+m+1,cmp);
        FOR(i,1,m)
            valid[i]=0;
        int ans = 0;
        FOR(i,1,m) 
            seat[a[i].S]=i;
        FOR(i,1,m) {
            int id = seat[i];
            valid[id] = 1;
            FOR(j,1,id-1)
                ans += valid[j];
        }
        cout << ans << '\n';
    }
}