#include <bits/stdc++.h>
#define TASK "1341F"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=500009;
vector<int> a[N];
vector<ii> ans;
int in[N];
int n,D;

void dfs(int u, int p) {
    int numv = a[u].size();
    if (u != 1) numv--;
    int now = in[u];
    int bck = now - 1;
    int done = 0;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (v == p) continue;
        now++;
        if (now == D + 1) {
            now = bck-numv+done;
            // x + numv - done = bck -> x= bck -numv +done
            ans.push_back({u,now++});
        }
        ++done;
        in[v]=now;
        ans.push_back({v,now});
        dfs(v,u);
    }
    if (u == 1) return;
    if (now != bck) ans.push_back({u,bck});
    ans.push_back({p,in[u]});
}
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    D=a[1].size();
    FOR(i, 2, n)
        D=max(D,(int)a[i].size());

    ans.push_back({1,0});
    dfs(1,0);
    cout << ans.size() << "\n";
    for (ii a:ans)
        cout << a.F << " " << a.S << "\n";

}
