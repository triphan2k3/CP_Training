#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKPOS.INP"
#define out "NKPOS.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
vector<int> res;
int n,m;
int ck[N];
int fir[N];
void findeulertour()
{
    stack<int> st;
    int state;
    st.push(1);
    while (st.size())
    {
        state=0;
        int u=st.top();
        for (int i=fir[u];i<a[u].size();i++)
        {
            int v=a[u][i].X;
            int stt=a[u][i].Y;
            if (ck[stt]) continue;
            ck[stt]=1;
            st.push(v);
            {
                fir[u]=i+1;
                state=1;
                break;
            }
        }
        if (!state)
        {
            res.push_back(u);
            st.pop();
        }

    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1,u;i<=n;i++)
        cin>>u;

    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        a[u].pb(mp(v,i));
        a[v].pb(mp(u,i));
    }
    findeulertour();
    cout<<m<<"\n";
    for (int i:res)
        cout<<i<<" ";
}
