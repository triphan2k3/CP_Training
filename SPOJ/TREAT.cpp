#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "TREAT.INP"
#define out "TREAT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],gcc[N],num[N],low[N],f[N],T,n;
stack<int> st;
void dfs(int u)
{
    num[u]=low[u]=++T;
    if (num[a[u]]==0)
    {
        dfs(a[u]);
        low[u]=min(low[u],low[a[u]]);
    }
    else low[u]=min(num[a[u]],low[u]);
    if (gcc[a[u]])
    {
        f[u]=f[a[u]]+1;
        gcc[u]=1;
        return;
    }
    st.push(u);
    int v=st.size();
    if (low[u]==num[u])
        while (st.size())
        {
            f[st.top()]=v;
            gcc[st.top()]=1;
            st.pop();
        }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
        if (!num[i]) dfs(i);

    for (int i=1;i<=n;i++)
        cout<<f[i]<<"\n";

}
