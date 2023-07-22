#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "TTRIP.INP"
#define out "TTRIP.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[101][101];
int check[N];
int n;
ll ans;

void floyd()
{
    for (int t=1;t<=n;t++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][t]+f[t][j]);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>f[i][j];
            if (f[i][j]==0 && i!=j) f[i][j]=MOD;
        }
    floyd();
    int now=1;

    while (1)
    {
        int next=0;
        for (int i=2;i<n;i++)
            if ((f[now][next]>f[now][i] || next==0) && check[i]==0 ) next=i;
        check[next]=1;
        if (f[now][next]==MOD || next==0) break;
        ans+=(ll)f[now][next];
        now=next;
    }
    ans+=(ll)f[now][n];
    cout<<ans;
}
