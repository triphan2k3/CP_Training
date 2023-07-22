#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SCOLLECT.INP"
#define out "SCOLLECT.OUT"
using namespace std;
const int N=130;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int a[N][N];
int f[2*N][N][N];
int n,m;

int get(char s)
{
    if (s=='.') return 0;
    if (s=='*') return 1;
    return -10000;
}
int solve(int buoc,int hang1,int hang2)
{
    int cot1=buoc-hang1+2;
    int cot2=buoc-hang2+2;
    if (a[hang1][cot1]<0 || a[hang2][cot2]<0) return -10000;

    int res=f[buoc-1][hang1][hang2];
        res=max(res,f[buoc-1][hang1-1][hang2-1]);
        res=max(res,f[buoc-1][hang1][hang2-1]);
        res=max(res,f[buoc-1][hang1-1][hang2]);

    if (hang1==hang2) return res+a[hang1][cot1];
    return res+a[hang1][cot1]+a[hang2][cot2];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<n;j++)
            a[i][j+1]=get(s[j]);
    }
    for (int b=0;b<=m+n-2;b++)
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                f[b][i][j]=-10000;
    f[0][1][1]=a[1][1];
    for (int buoc=1;buoc<=m+n-2;buoc++)
    {
        int dau=max(1,buoc-n);
        int cuoi=min(buoc+1,m);
        for (int hang1=dau;hang1<=cuoi;hang1++)
            for (int hang2=hang1;hang2<=cuoi;hang2++)
                f[buoc][hang1][hang2]=solve(buoc,hang1,hang2);
    }
    cout<<max(0,f[m+n-2][m][m]);
}
