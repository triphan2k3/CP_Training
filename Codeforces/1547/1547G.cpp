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
vector<int> e[N],scc[N];
int low[N],num[N],dp[N],in[N],vis[N],loop[N],cc[N],inf[N];
int T,nn;
vector<int> st;
void visit(int u) {
    low[u]=num[u]=++T;
    st.push_back(u);
    for(int v:e[u]) {
        if (num[v]) {
            low[u]=min(low[u],low[v]);
        }
        else {
            visit(v);
            low[u]=min(low[u],num[v]);
        }
    }
    if (low[u]==num[u]) {
        ++nn;
        int v=0,cnt=0;
        do {
            v=st.back();
            st.pop_back();
            cc[v]=nn;
            scc[nn].push_back(v);
            if (cnt || loop[v]) inf[nn]=1;
            cnt=1;
            num[v]=low[v]=N;
        } while (v!=u);
    }
}

void dfs(int u) {
    vis[u]=1;
    for (int v:e[u])
        if (!vis[v])
            dfs(v);
}
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        FOR(i,1,m) {
            int u,v;
            cin >> u >> v;
            if (u==v)
                loop[u]=1;
            else
                e[u].push_back(v);
        }
        nn=T=0;
        visit(1);
        FOR(i,1,n)
            if (cc[i] && inf[cc[i]])
                dfs(i);
        dp[nn]=1;
        FOD(i,nn,1) {
            dp[i]=min(dp[i],2);
            vector<int> c;
            for (int u:scc[i])
                for (int v:e[u])
                    if (cc[v]!= i && !in[cc[v]]) {
                        c.push_back(cc[v]);
                        in[cc[v]]=1;
                    }
            for (int v:c)
                dp[v]+=dp[i];
            for (int v:c)
                in[v]=0;
        }
        FOR(i,1,n) {
            if (!cc[i])
                cout << "0 ";
            else if (vis[i])
                cout << "-1 ";
            else if (dp[cc[i]]==1) cout << "1 ";
            else
                cout << "2 ";
        }
        cout << "\n";
        FOR(i,1,n) {
            e[i].clear();
            scc[i].clear();
            low[i]=num[i]=inf[i]=vis[i]=cc[i]=loop[i]=dp[i]=0;
        }
    }
}
