#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "LQDGONME.INP"
#define out "LQDGONME.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,m;
int f[N];
int a[11][N];
int pos[11][N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>> a[i][j];
            pos[i][a[i][j]]=j;
        }
    int ans=1;
    for (int i=1;i<=n;i++)
    {
        int val=a[1][i];
        f[val]=1;
        for (int j=1;j<=n;j++)
            if (val!=j)
            {
                int ok=0;
                for (int k=1;k<=m;k++)
                    if (pos[k][val]>pos[k][j]) ok++;
                if (ok<m) continue;
                f[val]=max(f[val],f[j]+1);
            }
        ans=max(ans,f[val]);
    }
    cout<<ans;
}
