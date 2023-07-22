#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define matrix vector<vector<ll> >
#define inp "CONNECTE.INP"
#define out "CONNECTE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9;
const ll INF=(ll)1e18+7;

matrix a={{2,2,2,0,1,1},
          {1,1,1,1,0,0},
          {1,1,1,1,0,0},
          {1,1,1,0,0,0},
          {1,1,1,0,0,0},
          {1,1,1,0,0,0}};
matrix r={{0,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,0,0}};

matrix operator*(matrix a,matrix b)
{
    matrix c=r;
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++)
            for (int k=0;k<6;k++)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
    return c;
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
    int n;
    cin>>n;
    if (n<=2)
    {
        if (n==1) cout<<0;
        else
        cout<<1;
        return 0;
    }
    matrix res=pow(n-2);
    ll finalres=0;
    for (int i=0;i<=3;i++)
        finalres+=res[i][0]+res[i][4]+res[i][5];
    finalres+=res[3][0]+res[3][4]+res[3][5];
    finalres%=MOD;
    cout<<finalres;
}
