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

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;cin >> t; 
    while (t--) {
        int n;
        cin >> n;
        priority_queue<ii> pq;
        FOR(i,1,n) {
            int x; cin >> x;
            if (x)
                pq.push({x,i});
        }
        vector<ii> ans;
        while (pq.size() > 1) {
            ii x =pq.top(); pq.pop();
            ii y =pq.top(); pq.pop();
            ans.pb({x.S,y.S});
            if (x.F>1)
                pq.push({x.F-1,x.S});
            if (y.F>1)
                pq.push({y.F-1,y.S});
        }
        cout << ans.size() << "\n";
        for(ii x:ans) cout << x.F << " " << x.S << "\n";

    }
}