#include <bits/stdc++.h>
#define ll unsigned long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CTNOWN.INP"
#define out "CTNOWN.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ll> a;
ll f[351][N];
int n;
int k=1;

int nt(int i)
{
    for (int j=2;j<i;j++)
        if (i%j==0) return 0;
    return 1;
}

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    a.pb(1);
    for (int i=2;i<=350;i++)
        if (nt(i))
    {
        int j=i;
        while (j<=350)
        {
            a.pb(j);
            j*=i;
        }
    }
    for (int i=0;i<=350;i++)
        f[0][i]=f[1][i]=1;
    for (int i=1;i<a.size();i++)
    {
        if (a[i]%a[i-1])
        {
            k++;
            for (int x=0;x<=350;x++)
                f[k][x]=f[k-1][x];
        }
        for (int j=350;j>=a[i];j--)
            f[k][j]=max(f[k][j],f[k-1][j-a[i]]*(ll)a[i]);
    }
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<f[k][n]<<"\n";
    }
}
