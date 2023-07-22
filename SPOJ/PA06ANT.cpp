#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define matrix vector<vector<ll>>
#define inp "PA06ANT.INP"
#define out "PA06ANT.OUT"
using namespace std;
const int N=(int)1e5+7;
const ll INF=(ll)1e18+7;
int p[8][8]={{0,1,0,2,3,0,0,0},
            {4,0,5,0,0,6,0,0},
            {0,7,0,8,0,0,9,0},
            {10,0,11,0,0,0,0,12},
            {13,0,0,0,0,14,0,15},
            {0,16,0,0,17,0,18,0},
            {0,0,19,0,0,20,0,21},
            {0,0,0,22,23,0,24,0},};

const int sz=24;
ll MOD;
matrix a,r;
void init()
{
    a.resize(sz);
    r.resize(sz);
    for (int i=0;i<sz;i++)
        {
            a[i].resize(sz);
            r[i].resize(sz);
        }
    for (int i=0;i<sz;i++)
        for (int j=0;j<sz;j++)
            a[i][j]=r[i][j]=0;
    for (int i=0;i<=7;i++)
        for (int j=0;j<=7;j++)
            for (int k=0;k<=7;k++)
                if (p[i][j] && p[j][k] && k!=i)
                    a[p[i][j]-1][p[j][k]-1]=1;
}
matrix operator *(matrix a,matrix b)
{
    matrix c=r;
    for (int i=0;i<sz;i++)
        for (int j=0;j<sz;j++)
            for (int k=0;k<sz;k++)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j]) % MOD;
    return c;
}

matrix pow(int n)
{
    if (n==1) return a;
    int m=n>>1;
    matrix t=pow(m);
    t=t*t;
    if (n%2)
        t=t*a;
    return t;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    char fi,se;
    int k;
    cin>>fi>>se>>k>>MOD;
    int bb=se-'A';
    int aa=fi-'A';
    init();
    if (k==1)
    {
        if (p[aa][bb])
            cout<<"1";
        else cout<<"0";
        return 0;
    }
    matrix res=pow(k-1);
    ll finalres=0;
    for (int i=0;i<8;i++)
        for (int j=0;j<8;j++)
            if (p[aa][i] && p[j][bb])
                {
                    finalres+=res[p[aa][i]-1][p[j][bb]-1];
                    if (finalres>=MOD) finalres-=MOD;
                }
    cout<<finalres;
}
