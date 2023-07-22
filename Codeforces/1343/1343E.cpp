#include <bits/stdc++.h>
#define TASK "1343E"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=1; i>b ; i--)
using namespace std;
const int N=300001;
vector<int> a[N];
ll p[N];
int dist[N],ok[N],d[N][3];
int t,n,m,x,y,z;

void BFS(int u, int I)
{
    deque<int> q;
    FOR(i, 1, n)
        ok[i]=dist[i]=0;
    ok[u]=1;

    q.pb(u);
    while (q.size()) {
        int v=q.back();
        q.pop_back();
        FOR(i, 0, a[v].size()-1) {
            int nx=a[v][i];
            if (ok[nx]) continue;
            ok[nx]=1;
            dist[nx]=dist[v]+1;
            q.push_front(nx);
        }
    }
    FOR(i, 1, n)
        d[i][I]=dist[i];
    return;
}
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y >> z;

        FOR(i, 1 ,m)
            cin >> p[i];
        sort(p+1,p+m+1);
        FOR(i, 1, m)
            p[i]+=p[i-1];

        FOR(i, 1, m) {
            int u,v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }


        BFS(x,0);
        BFS(y,1);
        BFS(z,2);

        ll ans=1e16;
        FOR(u, 1, n)
        {
            int au=d[u][0]; // x->u =
            int bu=d[u][1];
            int cu=d[u][2];
            if (au+bu+cu>m) continue;
            ans=min(ans,p[au+bu+cu]+p[bu]);
        }
        cout<<ans<<"\n";
        FOR(i, 1, n) {
            a[i].clear();
            d[i][0]=d[i][1]=d[i][2]=0;
        }

    }
}
