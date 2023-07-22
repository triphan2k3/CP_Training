#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "ROPER.INP"
#define out "ROPER.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],ck[N],gcc[N];
int n,m,T;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        if (!gcc[i])
        {
            gcc[i]=++T;
            int t=i;
            while (a[t]!=i)
            {
                t=a[t];
                gcc[t]=T;
            }
        }
    int u,v;
    while (m--)
    {
        cin>>u>>v;
        if (gcc[u]==gcc[v] || (gcc[u]==gcc[1] && gcc[v]==gcc[2]) || (gcc[u]==gcc[2] && gcc[v]==gcc[1]))
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}
