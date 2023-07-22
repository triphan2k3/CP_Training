#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define NAME "BARIC"
#define inp NAME".INP"
#define out NAME".OUT"
using namespace std;
const int N=(int)1e2+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int s1[N],s3[N],a[N];
int f[N][N],s2[N][N];
int n,e;

int ttd(int i)
{
    return i<0 ? -i:i;
}

void prepare()
{
    for (int i=2;i<=n;i++)
        for (int j=1;j<i;j++)
            s1[i]+=2*ttd(a[i]-a[j]);

    for (int i=n-1;i>=1;i--)
        for (int j=i+1;j<=n;j++)
            s3[i]+=2*ttd(a[i]-a[j]);

    for (int i=1;i<n;i++)
        for (int j=i+2;j<=n;j++)
            for (int k=i+1;k<j;k++)
                s2[i][j]+=ttd(a[i]+a[j]-2*a[k]);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>e;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    prepare();
    //fij la cost khi chon i so so cuoi la j
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (i>j)
            {
                f[i][j]=MOD;
                continue;
            }
            if (i==1)
            {
                f[i][j]=s1[j]+s3[j];
                continue;
            }
            f[i][j]=MOD;
            for (int k=1;k<j;k++)
                f[i][j]=min(f[i][j],f[i-1][k]-s3[k]+s2[k][j]+s3[j]);
        }
    for (int k=1;k<=n;k++)
    {
        int res=MOD;
        for (int i=k;i<=n;i++)
            res=min(f[k][i],res);
        if (res>e) continue;
        cout<<k<<" "<<res;
        return 0;
    }
}
