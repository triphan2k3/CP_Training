#include <bits/stdc++.h>
#define ll long long
#define ii pair<double,double>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKPOLY.INP"
#define out "NKPOLY.OUT"
#define double long double
using namespace std;
const int N=207;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

double f1[N][N],f2[N][N];
ii a[N];

double s(int i,int j,int k)
{
    return abs((a[j].X-a[i].X)*(a[k].Y-a[i].Y)-(a[k].X-a[i].X)*(a[j].Y-a[i].Y))/2.0;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].X>>a[i].Y;

    for (int i=0;i+2<n;i++)
        f1[i][i+2]=f2[i][i+2]=s(i,i+1,i+2);

    for (int sz=4;sz<=n;sz++)
        for (int i=0;i+sz-1<n;i++)
        {
            int j=i+sz-1;
            f2[i][j]=1e18;
            for (int k=i+1;k<j;k++)
            {
                 f1[i][j]=max(f1[i][j],max(f1[i][k],max(f1[k][j],s(i,j,k))));
                 f2[i][j]=min(f2[i][j],max(f2[i][k],max(f2[k][j],s(i,j,k))));
            }
        }
    cout<<setprecision(1)<<fixed<<f1[0][n-1];
    cout<<"\n";
    cout<<setprecision(1)<<fixed<<f2[0][n-1];
}
