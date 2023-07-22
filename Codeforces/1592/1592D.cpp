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
vector<int> e[N];
vector<int> x;
int sz[N],s[N];
int n,found;
void dfs(int u,int p,int Time) {
    sz[u] = 1;
    int big=0;
    for(int v:e[u])
    if (v!=p && s[v]==Time) {
        dfs(v,u,Time);
        sz[u]+=sz[v];
        if (!big || sz[v]>sz[big]) big = v;
    }
    if (sz[u]*2 >= n && !found) {
        found = u;
        x.pb(u);
    }
    if (!found) x.pb(u);
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
    cin >> n;
    FOR(i,1,n)
        e[i].clear();
    FOR(i,1,n-1) {
        int u,v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    FOR(i,1,n)
        s[i] = 1;
    cout << "? " << n << " ";
    FOR(i,1,n)
        cout << i << " ":
    cout << "\n";
    cout.flush();
    int ans; cin >> ans;
    FOR(Time,1,11) {
        FOR(i,1,n)
            sz[i] = 0;
        x.clear();
        FOR(i,1,n) if (s[i]==Time)
        dfs(i,0,Time);
        cout << "? " << x.size() << " ";
        for(int y:x)
            cout << y << " ";
        cout << "\n";
        cout.flush();
        int ck; cin >> ck;
        if (ck==ans) {
            for(int y:x)
                s[y]++;
            n = x.size();
        } else {
            for(int y:x)
                s[y]--;
            FOR(i,1,n)
                s[i]++;
            n-=x.size();
        }
    }
    
}