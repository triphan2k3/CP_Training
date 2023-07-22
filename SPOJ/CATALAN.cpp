#include <bits/stdc++.h>
#define ii pair<int,int>
#define X first
#define Y second
#define ll long long
#define inp "CATALAN.INP"
#define out "CATALAN.OUT"
using namespace std;
int n;
int x[100];
int cnt;
long long f[200][200];

void solve1(int k)
{
    int r1,r2,pre=0;
    x[2*n]=0;
    for (int i=2*n-1;i>=0;i--)
    {
        r1=f[i][pre+1];
        if (pre!=0) r2=f[i][pre-1]; else r2=-1;
        if (r2>=k)
        {
            x[i]=pre-1;
            pre--;
        }
        else
        {
            x[i]=pre+1;
            pre++;
            if (r2!=-1) k-=r2;
        }

    }
}
long long solve2()
{
    int res=0;
    for (int i=2*n-1;i>=0;i--)
    {
        if (x[i]>x[i+1] && x[i]>1)
            res+=f[i][x[i]-2];
    }
    return res+1ll;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    f[0][0]=1;
    for (int i=1;i<=2*n;i++)
        for (int j=0;j<=n;j++)
        {
            f[i][j]=f[i-1][j+1];
            if (j>0) f[i][j]+=f[i-1][j-1];
        }
    for (int i=2*n;i>=0;i--)
        cin>>x[i];

    cout<<solve2()<<"\n";
    int q;
    cin>>q;
    solve1(q);
    for (int i=2*n;i>=0;i--)
        cout<<x[i]<<" ";
}

