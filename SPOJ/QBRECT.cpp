#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBRECT.INP"
#define out "QBRECT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[1001][1001];
int f[1001][1001];
int st[1001];
int l[1001];
int r[1001];
int m;
int n;
void setup()
{
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=(a[i][j]) ? f[i-1][j]+1:0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        cin>>a[i][j];
    int res=0;
    setup();
    for (int i=1;i<=m;i++)
    {
        int top=0;
        for (int j=1;j<=n;j++)
        {
            while (top>0 && f[i][st[top]]>=f[i][j]) top--;
            l[j]=st[top]+1;
            st[++top]=j;
        }
        top=0;
        for (int j=n;j;j--)
        {
            while (top>0 && f[i][st[top]]>=f[i][j]) top--;
            r[j]=(top==0) ? n:st[top]-1;
            st[++top]=j;
        }
        for (int j=1;j<=n;j++)
            res=max(res,f[i][j]*(r[j]-l[j]+1));
    }
    cout<<res;
}
