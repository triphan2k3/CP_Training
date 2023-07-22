#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NUMBER.INP"
#define out "NUMBER.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
stack<int> st;
int n,m,T,t,G,res;
int num[N],low[N],ck[N],gcc[N];

void dfs(int u)
{
    num[u]=low[u]=++T;
    st.push(u);
    for (int v:a[u])
    {
        if (gcc[v]) continue;
        if (num[v]) low[u]=min(low[u],num[v]);
        else
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if (num[u]==low[u])
    {
        gcc[u]=++G;
        while (st.top()!=u)
        {
            gcc[st.top()]=G;
            st.pop();
        }
        st.pop();
    }
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>t;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
    }
    for (int i=1;i<=n;i++)
        if (!num[i])
            dfs(i);

    for (int i=1;i<=n;i++)
        for (int v:a[i])
            if (gcc[i]!=gcc[v])
                ck[gcc[i]]=1;

    for (int i=1;i<=G;i++)
        if (!ck[i] && i!=gcc[t]) res++;

    cout<<res;
}
