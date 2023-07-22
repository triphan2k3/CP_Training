#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define pll pair<ll,ll>
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
int m,n;
vector<pll> e[N];
ll d[N];
void solve() {
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    FOR(i,1,n)
        pq.push({d[i],i});
    while (pq.size()) {
        ll u=pq.top().S;
        ll du=pq.top().F;
        pq.pop();
        if (du!=d[u])
            continue;
        for(pll edge:e[u]) {
            ll v=edge.F;
            ll w=edge.S;
            if (d[v]>du+w) {
                d[v]=du+w;
                pq.push({d[v],v});
            }
        }
    }
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,m) {
        ll u,v,w;
        cin >> u >> v >> w;
        w=w*2;
        e[u].pb({v,w});
        e[v].pb({u,w});
    }
    FOR(i,1,n)
        cin >> d[i];
    solve();
    FOR(i,1,n)
        cout << d[i] << " ";

}
