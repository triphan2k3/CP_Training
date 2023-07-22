#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MESSAGE.INP"
#define out "MESSAGE.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
stack<int> st;
int m,n,T,G;
int num[N],low[N],gcc[N],ck[N];

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
    if (low[u]>=num[u])
    {
        gcc[u]=++G;
        while (st.top()!=u)
        {
            gcc[st.top()]=G;
            st.pop();
        }
        st.pop();
    }
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
    for (int i=1;i<=n;i++)
        if (!num[i])
            dfs(i);

    for (int i=1;i<=n;i++)
        for (int u:a[i])
            if (gcc[i]!=gcc[u]) ck[gcc[u]]=1;

    int res=G;
    for (int i=1;i<=G;i++)
        if (ck[i]) res--;

    cout<<res;
}
