#include <bits/stdc++.h>
#define TASK "1385E"
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

vector<int> e2[N];
vector<int> e1[N];
int n,m,T;
int visit[N],vao[N];

int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        T=0;
        FOR(i,1,n) {
            visit[i]=vao[i]=0;
            e1[i].clear();
            e2[i].clear();
        }

        FOR(i,1,m) {
            int x,u,v;
            cin >> x >> u >> v;
            if (x) {
                e1[u].push_back(v);
                vao[v]++;
            }
            else
                e2[u].push_back(v);
        }
        queue<int> q;
        FOR(v,1,n)
            if (!vao[v])
                q.push(v);

        while(q.size()) {
            int u=q.front();
            q.pop();
            visit[u]=++T;
            for (int v:e1[u]) {
                if (--vao[v]==0)
                    q.push(v);
            }
        }
        if (T<n) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int u=1;u<=n;u++) {
            for (int v:e1[u])
                cout << u << " " << v << "\n";
            for (int v:e2[u])
                if (visit[u] < visit[v])
                    cout << u << " " << v << "\n";
                else
                    cout << v << " " << u << "\n";

        }
    }
}
