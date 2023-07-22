#include <bits/stdc++.h>
#define TASK ""
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
vector<int> vis;
vector<ii> c;
int h[N],ret[N],visit[N],Visit[N];
int n,m;
void dfs(int u) {
    visit[u]=1;
    for (int v:a[u]) if (!visit[v]) {
        h[v]=h[u]+1;
        dfs(v);
    }
    vis.pb(u);
}
void Dfs(int u) {
    Visit[u]=1;

    for(int v:a[u]) if (!Visit[v]) {
        h[v]=h[u]+1;
        Dfs(v);
        ret[u]=max(ret[u],ret[v]+1);
    }
}
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,m) {
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    FOR(i,1,n)
        if (!visit[i]) {
            dfs(i);
            int v=i,ma=0;
            for (int u:vis) {
                if (h[u]>h[v]) {
                    ma=h[u];
                    v=u;
                }
            }
            h[v]=0;
            Dfs(v);
            for(int u:vis) {
                if (ret[u]+h[u]==ret[v] && abs(h[u]-ret[u])<=1) {
                    c.push_back({ret[v],u});
                    break;
                }
            }
            vis.clear();
        }
    if (c.size()==1) {
        cout << c[0].F;
        return 0;
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int ans1=c[0].F;
    int ans2=c[1].F;
    int part1 = (ans1+1)/2;
    int part2 = (ans2+1)/2;
    int part3 = c.size()>=3 ? (c[2].F+1)/2:-100;
    int ans=max(max(ans1,part1+part2+1),part2+part3+2);
    cout << ans << "\n";
    FOr(i,1,c.size())
        cout << c[i].S << " " << c[0].S << "\n";
}
