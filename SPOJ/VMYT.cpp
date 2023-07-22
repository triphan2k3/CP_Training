#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define matrix vector<vector<ll>>
#define inp "VMYT.INP"
#define out "VMYT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
matrix a,r;
int n,k;
void makematrix()
{
    a.resize(k);
    for (int i=0;i<k;i++)
        a[i].resize(k);
    for (int i=1;i<k;i++)
        for (int j=1;j<k;j++)
            a[i][j]=0;
    r=a;
    for (int i=0;i+1<k;i++)
        a[i][i+1]=a[i][0]=1;
    a[k-1][0]=1;
}

matrix operator *(matrix a,matrix b)
{
    matrix c=r;
    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            for (int z=0;z<k;z++)
                c[i][j]=(c[i][j]+a[i][z]*b[z][j])%(MOD-1ll);
    return c;
}
ll luythua(int a,int n)
{
    if (n==0) return 1;
    if (n==1) return a;
    ll t=luythua(a,n>>1);
    t=(t*t) % MOD;
    if (n%2)
        t=(t*a) % MOD;
    return t;
}
matrix pow(int n)
{
    if (n==1) return a;
    matrix t=pow(n>>1);
    t=t*t;
    if (n%2) t=t*a;
    return t;
}

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ll res=1;
    cin>>n>>k;
    makematrix();
    matrix tres=pow(n-k);
    for (int i=0;i<k;i++)
    {
        ll tp;
        cin>>tp;
        res*=luythua(tp,tres[k-i-1][0]);
        res%=MOD;
    }
    cout<<res;
}
