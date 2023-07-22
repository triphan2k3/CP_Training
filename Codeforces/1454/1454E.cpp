#include <bits/stdc++.h>
#define TASK "1454E"
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
vector<int> a[N];
int visit[N];
ll f[N];
int n,kt;

void dfs(int u,int p) {
    visit[u]=1;
    for (int v:a[u])
    if (v!=p) {
        if (visit[v]) {
            kt=v;
        }
        else {
            dfs(v,u);
            if (kt == u) {
                f[u]+=2*(f[v]+1)+1;
                kt=0;
            }
            else
                f[u]+=f[v]+1;
        }
    }
}

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,1,n) {
            a[i].clear();
            f[i]=visit[i]=0;
        }

        FOR(i,1,n) {
            int u,v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        int res=0;
        dfs(1,0);
        FOR(i,1,n)
            res+=f[i];
        cout << res << "\n";
    }
}
