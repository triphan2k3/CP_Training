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
vector<int> a[N];
int d[N],cnt[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;cin >> t ;
    while (t--) {
        int n,k;
        cin >> n >> k;
        if (n==1) {
            cout << "0\n";
            continue;
        }
        FOR(i,1,n) {
            a[i].clear();
            d[i]=0;
            cnt[i] = 0;
        }
        FOR(i,1,n-1) {
            int u,v;
            cin >> u >> v;
            cnt[u]++;
            cnt[v]++;
            a[u].pb(v);
            a[v].pb(u);
        }
        queue<int> q;
        FOR(i,1,n)
            if (a[i].size()==1) {
                q.push(i);
                d[i]=1;
                cnt[i]--;
            }
        int ans = n;
        while (q.size()) {
            int u = q.front();
            if (d[u]<=k) ans--;
            q.pop();
            for(int v:a[u]) if (!d[v]){
                cnt[v]--;
                if (!d[v] && cnt[v]==1) {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        cout << ans << "\n";
    }
}