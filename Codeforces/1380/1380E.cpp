#include <bits/stdc++.h>
#define TASK "1380E"
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
int dsu[N];
int n,m,ans;
vector<int> data[N];

int root(int u) {
    if (dsu[u]<0) return u;
    dsu[u]=root(dsu[u]);
    return dsu[u];
}
void gop(int a,int b) {
    int u=root(a);
    int v=root(b);
    if (u==v) return;
    if (dsu[u] > dsu[v])
        swap(u,v);
    dsu[u]+=dsu[v];

    for (int i:data[v]) {
        int x=root(i);
        if (i<2*n) {
            int y=root(i+1);
            if (y==u) ans--;
        }
        if (i-1>n) {
            int y=root(i-1);
            if (y==u) ans--;
        }
    }
    for (int i:data[v]) {
        data[u].push_back(i);
        dsu[i]=u;
    }
    data[v].clear();
    dsu[v]=u;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        int t;
        cin >> t;
        data[t].push_back(i+n);
        dsu[i+n]=t;

    }
    for (int i=1;i<=m;i++)
        dsu[i]=-data[i].size();
    ans=n-1;
    for (int i=1;i<n;i++)
        if (dsu[i+n]==dsu[i+n+1]) ans--;
    cout << ans << "\n";
    for (int i=1;i<m;i++) {
        int a,b;
        cin >> a >> b;
        gop(a,b);
        cout << ans << "\n";
    }
}
