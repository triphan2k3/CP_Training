#include <bits/stdc++.h>
#define inp "1337E.INP"
#define out "1337E.OUT"
using namespace std;
const int N=3001;
const int MOD=998244353;
int f[N][N];
int m,n;
string s,t;

void add(int &a,int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
}
bool ok(int i,int j)
{
    if (j>m) return 1;
    return s[i]==t[j];
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>s>>t;
    n=s.size();
    m=t.size();

    s=' '+s;
    t=' '+t;

    for (int i=1;i<=n;i++)
        if (ok(1,i)) f[1][i]=2;

    for (int i=2;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
        {
            if (ok(i,j))     add(f[i][j],f[i-1][j+1]);
            if (ok(i,j+i-1)) add(f[i][j],f[i-1][j]);
        }
    int ans=0;
    for (int i=m;i<=n;i++)
        add(ans,f[i][1]);

    cout<<ans;
}
