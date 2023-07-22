#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MREPLBRC.INP"
#define out "MREPLBRC.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,kt;
int mau[N],a[N];
string s;
ll f[N][N];
ll get(int i,int j)
{
    if (a[i]<0 || a[j]>0) return 0;
    if (a[j]==0 && a[i]==0) return 3;
    if (a[i]+a[j]==0) return 1;
    if (a[i]*a[j]==0) return 1;
    return 0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>s;
    mau['(']=1;
    mau[')']=-1;
    mau['[']=2;
    mau[']']=-2;
    mau['{']=3;
    mau['}']=-3;
    cerr<<s;
    for (int i=0;i<n;i++)
        a[i]=mau[s[i]];
    for (int i=0;i+1<n;i++)
        f[i][i+1]=get(i,i+1);
    for (int i=1;i<=n;i++)
        f[i][i-1]=1;
    for (int sz=4;sz<=n;sz+=2)
        for (int i=0;i+sz-1<n;i++)
        {
            int j=i+sz-1;
            if (a[i]<0 || a[j]>0) continue;

            f[i][j]=f[i+1][j-1]*get(i,j);
            for (int k=i+1;k<=j-2;k+=2)
            {
                if (a[i]<0 || a[k]>0) continue;
                f[i][j]+=get(i,k)*f[i+1][k-1]*f[k+1][j];
                if (f[i][j]>=100000)
                {
                    kt=1;
                    f[i][j]%=100000;
                }
            }
        }
    if (kt==0) cout<<f[0][n-1];
    else
    {
        int t=f[0][n-1];
        if (t==0)
        {
            cout<<"00000";
            return 0;
        }
        while (t*10<100000)
        {
            cout<<0;
            t*=10;
        }
        cout<<f[0][n-1];
    }
}
