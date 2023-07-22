#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "LEM3.INP"
#define out "LEM3.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t[17][100000],c[17][17],b[17],n,firs,last;
int getbit(int i,int state)
{
    return (state>>i) & 1;
}
int offbit(int i,int state)
{
    return state & (~(1<<i));
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>c[i][j];
    firs=1;
    last=(1<<n)-1;
    for (int i=1;i<=n;i++)
        for (int state=1;state<=last;state++)
            t[i][state]=MOD;
    for (int i=1;i<=n;i++)
        t[i][1<<(i-1)]=0;

    for (int st=firs;st<=last;st++)
    {
        int k=0;
        for (int i=1;i<=n;i++)
            if (getbit(i-1,st))
                b[++k]=i;

        for (int i=1;i<=k;i++)
        {
            int u=b[i];
            int pres=offbit(u-1,st);
            for (int j=1;j<=k;j++)
                if (b[j]!=u)
                    t[u][st]=min(t[u][st],t[b[j]][pres]+c[b[j]][u]);
        }
    }
    int res=MOD;
    for (int i=1;i<=n;i++)
        res=min(res,t[i][last]);
    cout<<res;
}
