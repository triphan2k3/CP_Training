#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SAFENET2.INP"
#define out "SAFENET2.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,m,sz,T,res;
int num[N],low[N];
ii e[N];
vector<vector<int>> a;
stack<int> st;
void dfs(int u,int p)
{
    num[u]=low[u]=++T;
    st.push(u);
    for (int v:a[u])
    {
        if (v==p) continue;
        if (num[v]) low[u]=min(low[u],num[v]);
        else
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]<num[u]) continue;
            sz=2;
            while (st.top()!=v)
            {
                //cout<<st.top()<<" ";
                st.pop();
                sz++;
            }
            st.pop();
            //cout<<v<<" "<<u<<"\n";
            res=max(res,sz);
        }
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
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if (m==0) res=1; else res=2;
    for (int i=1;i<=n;i++)
        if (!num[i])
        {
            while (st.size()) st.pop();
            dfs(i,0);
        }
    cout<<res;
}
