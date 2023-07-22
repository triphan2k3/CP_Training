#include <bits/stdc++.h>
#define TASK "1385F"
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
int del[N],chil[N],sz[N];
vector<int> a[N];

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        FOR(i,1,n) {
            chil[i]=del[i]=0;
            a[i].clear();
        }
        FOR(i,1,n-1) {
            int u, v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        if (k==1) {
            cout << n-1 << "\n";
            continue;
        }
        queue<int> q;
        FOR(i,1,n)
            if (a[i].size()==1) {
                chil[a[i][0]]++;
                del[i]=1;
                if (chil[a[i][0]]==k)
                    q.push(a[i][0]);
            }
        FOR(i,1,n)
            sz[i]=a[i].size();
        int ans=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            ans+=chil[u]/k;
            sz[u]-=(chil[u]-(chil[u]%k));
            if (sz[u]==1) {
                del[u]=1;
                for(int v:a[u])
                    if (!del[v]) {
                        chil[v]++;
                        if (chil[v]==k) q.push(v);
                    }
            }
            chil[u]%=k;
        }
        cout << ans << "\n";
    }
}
