#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<int>> a;
stack<int> st;
int num[N],low[N],gcc[N],tp[N],in[N],ou[N];
int m,n,T,G,numi,posi,numo,poso;
void dfs(int u)
{
    num[u]=low[u]=++T;
    st.push(u);
    for (int v:a[u])
    {
        if (gcc[v]) continue;
        if (!num[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
            continue;
        }
        low[u]=min(low[u],num[v]);
    }
    if (low[u]<num[u]) return;
    tp[++G]=u;
    gcc[u]=G;
    while (st.top()!=u)
    {
        gcc[st.top()]=G;
        st.pop();
    }
    st.pop();
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
    }
    for (int i=1;i<=n;i++)
        if (!num[i]) dfs(i);
    for (int u=1;u<=n;u++)
        for (int v:a[u])
        {
            if (gcc[u]==gcc[v]) continue;
            in[gcc[v]]=1;
            ou[gcc[u]]=1;
        }

    for (int i=1;i<=G;i++)
    {
        if (in[i] && ou[i]) continue;
        if (!in[i])
        {
            numi++;
            posi=i;
            if (numi==2)
            {
                cout<<"NO";
                return 0;
            }
        }
        if (!ou[i])
        {
            numo++;
            poso=i;
            if (numo==2)
            {
                cout<<"NO";
                return 0;
            }
        }

    }
    cout<<"YES\n"<<tp[poso]<<" "<<tp[posi];
}
