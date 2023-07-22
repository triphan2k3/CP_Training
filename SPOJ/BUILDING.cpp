#include <bits/stdc++.h>
#define TASK "building"
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
struct hcn {
    int x,y,p,q;
};

hcn a[N];
int low[N],num[N],par[N],sz[N];
vector<int> e[N];
vector<int> path;
int n,T;

void nen() {
    vector<int> x,y;
    map<int,int> mx,my;
    FOR(i,1,n) {
        x.push_back(a[i].x);
        x.push_back(a[i].p);
        y.push_back(a[i].y);
        y.push_back(a[i].q);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    int tx=0,ty=0;
    mx[x[0]]=my[y[0]]=1;
    for (int i=0;i<x.size();i++) {
        mx[x[i]]=(x[i]==x[i-1]) ? tx:++tx;
        my[y[i]]=(y[i]==y[i-1]) ? ty:++ty;
    }
    FOR(i,1,n) {
        a[i].x=mx[a[i].x];
        a[i].y=my[a[i].y];
        a[i].p=mx[a[i].p];
        a[i].q=my[a[i].q];
    }
}

bool cmpiii(iii a,iii b) {
    return  a.F.F != b.F.F ? a.F.F < b.F.F : a.F.S>b.F.S;
}
void buildgraph() {
    set<int> s;
    vector<iii> X[2*n+1];
    FOR(i,1,n) {
        X[a[i].x].push_back({{a[i].y,-1},i});
        X[a[i].x].push_back({{a[i].q, 1},i});
        X[a[i].p].push_back({{a[i].y,-1},i});
        X[a[i].p].push_back({{a[i].q, 1},i});
    }
    FOR(i,1,2*n) {
        sort(X[i].begin(),X[i].end(),cmpiii);
        for (iii t:X[i]) {
            int u=t.S;
            int add=t.F.S;
            if (add==-1) {
                s.erase(u);
                continue;
            }
            set<int> ns;
            while (s.size()) {
                int v=*s.begin();
                s.erase(s.begin());
                ns.insert(v);
                e[u].push_back(v);
                e[v].push_back(u);
            }
            s=ns;
            s.insert(u);
        }
    }
}
void mirror() {
    FOR(i,1,n) {
        swap(a[i].x,a[i].q);
        swap(a[i].y,a[i].p);
    }
}

void dfs(int u,int p) {
    low[u]=num[u]=++T;
    par[u]=p;
    sz[u]=1;
    path.push_back(u);
    for (int v:e[u]) if (v!=p) {
        if (num[v])
            low[u]=min(low[u],num[v]);
        else {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            sz[u]+=sz[v];
        }
    }
}
int main() {
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n)
        cin >> a[i].x >> a[i].y >> a[i].p >> a[i].q;
    nen();
    buildgraph();
    mirror();
    buildgraph();

    int ans=n+1;
    FOR(i,1,n)
        if (!num[i]) {
            path.clear();
            dfs(i,0);
            for (int v:path) if (par[v]) {
                if (num[v]==low[v])
                    ans=min(ans,abs(sz[i]-2*sz[v]));
            }
        }
    if (ans==n+1)
        ans=-1;
    cout << ans;
}
