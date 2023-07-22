#include <bits/stdc++.h>
#define TASK "UPGRANET"
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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct edge {
    int u,v,w;

};
edge e[N];
vector<ii> a[N];
vector<int> mst;
int ptab[N][21],pmin[N][21];
int h[N],dsu[N];
int m,n;

int head(int u) {
    return dsu[u]<0 ? u:dsu[u]=head(dsu[u]);
}
int join(int u,int v) {
    u=head(u);
    v=head(v);
    if (u==v)
        return 0;
    if (dsu[u]<dsu[v])
        swap(u,v);
    dsu[v]+=dsu[u];
    dsu[u]=v;
    return 1;
}

bool cmp(edge e,edge f) {return e.w > f.w;}

void findmst() {
    sort(e+1,e+m+1,cmp);
    FOR(i,1,n)
        dsu[i]=-1;
    FOR(i,1,m)
        if (join(e[i].u,e[i].v))
            mst.push_back(i);
}

void dfs(int u,int p) {
    for (ii e:a[u]) {
        int v=e.F;
        int w=e.S;
        if (v==p) continue;
        h[v]=h[u]+1;
        ptab[v][0]=u;
        pmin[v][0]=w;
        dfs(v,u);
    }
}

void setup() {
    FOR(k,1,20)
        FOR(u,1,n)
        if (h[u] >= 1<<k) {
            int v=ptab[u][k-1];
            ptab[u][k]=ptab[v][k-1];
            pmin[u][k]=min(pmin[u][k-1],pmin[v][k-1]);
        }
}
int findans(int i) {
    int u=e[i].u;
    int v=e[i].v;
    int w=e[i].w;

    int ans=MOD;
    if (h[u]>h[v]) swap(u,v);
    FOD(k,20,0)
        if (h[v]-(1<<k) >= h[u]) {
            ans=min(ans,pmin[v][k]);;
            v=ptab[v][k];
        }
    if (u==v)
        return ans-w;
    FOD(k,20,0)
        if (ptab[u][k] != ptab[v][k]) {
            ans=min(ans,min(pmin[u][k],pmin[v][k]));
            u=ptab[u][k];
            v=ptab[v][k];
        }
    ans=min(ans,min(pmin[u][0],pmin[v][0]));
    return ans-w;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,m)
        cin >> e[i].u >> e[i].v >> e[i].w;
    findmst();
    for (int i:mst) {
        a[e[i].u].push_back({e[i].v,e[i].w});
        a[e[i].v].push_back({e[i].u,e[i].w});
    }
    dfs(1,0);
    setup();
    ll ans=0;
    FOR(i,1,m)
        ans+=findans(i);
    cout << ans;
}
