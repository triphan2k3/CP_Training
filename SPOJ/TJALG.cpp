#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "TJALG.INP"
#define out "TJALG.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
int n,m,T,res;
int num[N],low[N],gcc[N];
stack<int> st;
void dfs(int u)
{
    num[u]=low[u]=++T;
    st.push(u);
    for (int v:a[u])
        if (num[v] && gcc[v]==0)
            low[u]=min(low[u],num[v]);
        else
        if (!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    if (low[u]>=num[u])
    {
        while (st.top()!=u)
        {
            gcc[st.top()]=1;
            st.pop();
        }
        st.pop();
        gcc[u]=1;
        res++;
    }
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
    }
    for (int u=1;u<=n;u++)
    {
        if (num[u]) continue;
        dfs(u);
    }
    cout<<res;
}
