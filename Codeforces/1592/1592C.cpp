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
int n,k,nxor,cnt;
int a[N],x[N];
vector<int> e[N];

void dfs(int u,int p) {
    x[u] = a[u];
    for(int v:e[u]) if (v!=p) {
        dfs(v,u);
        x[u]^=x[v];
    }
    if (x[u]==nxor) {
        cnt++;
        x[u]=0;
    }
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
        cin >> n >> k; 
        nxor = 0;
        FOR(i,1,n)  {
            e[i].clear();
            x[i] = 0;
            cin >> a[i];
            nxor^=a[i];
        }
        
        FOR(i,1,n-1) {
            int u,v;
            cin >> u >> v;
            e[u].pb(v);
            e[v].pb(u);
        }
        
        if (nxor==0) {
            cout << "YES\n";
            continue;
        }
        if (k==2) {
            cout << "NO\n";
            continue;
        }
        cnt = 0;
        dfs(1,0);
        if (cnt>=3) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}