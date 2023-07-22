#include <bits/stdc++.h>
#define ll long long
#define ii pair<double,double>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "LEM.INP"
#define out "LEM.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ii a[N],b[N];
int m,n;
double kq=5e9;
double sqr(double a)
{
    return a*a;
}
double dis(ii a,ii b)
{
    return sqrt(sqr(b.X-a.X)+sqr(b.Y-a.Y));
}
double kc(ii x, ii u, ii v)
{
    double a=v.Y-u.Y;
    double b=u.X-v.X;
    double c=-(a*u.X+b*u.Y);
    double A=-b;
    double B=a;
    double C=-(x.X*A+x.Y*B);
    double ygd=(-C*a+c*A)/(a*B-A*b);
    double xgd=(-C*b+c*B)/(b*A-B*a);
    if ((ygd>max(u.Y,v.Y)) || (ygd<min(u.Y,v.Y))) return 5e9;
    return dis(x,{xgd,ygd});
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i].X>>a[i].Y;

    for (int j=1;j<=m;j++)
    {
        cin>>b[j].X>>b[j].Y;
        for (int i=1;i<=n;i++)
            kq=min(kq,dis(a[i],b[j]));
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            {
                if (i!=n)
                    kq=min(kq,kc(b[j],a[i],a[i+1]));
                if (j!=m)
                    kq=min(kq,kc(a[i],b[j],b[j+1]));
            }
    cout<<setprecision(3)<<fixed<<kq;
}
