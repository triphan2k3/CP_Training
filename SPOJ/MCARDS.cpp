#include <iostream>
using namespace std;
bool check[5];
int val[5],mau[1000],d[1000],a[1000],s[1000],res,ma,n,c;


void np(int i)
{
    int l=0,r=ma;
    do
    {
        int m=(l+r)/2;
        if (a[s[m]]>=a[i]) r=m;
        else l=m;
    } while (r-l>1);
    if (a[s[r]]<a[i]) l=r;
    if (l+1>ma)
    {
        ma++;
        s[ma]=i;
    } else
    if (a[s[l+1]]>a[i]) s[l+1]=i;
}
void solve()
{
    for (int i=1;i<=n*c;i++)
        a[i]=val[mau[i]]*1000+d[i];

    ma=0;
    for (int i=1;i<=n*c;i++)
        np(i);

    res=max(res,ma);

}
void setup(int i)
{
    if (i==c+1)
    {
        solve();
        return;
    }

    for (int j=1;j<=c;j++)
    if (!check[j])
    {
        val[j]=i;
        check[j]=true;
        setup(i+1);
        check[j]=false;
    }
}
int main()
{
    cin >> c >> n ;
    for (int i=1;i<=n*c;i++)
        cin >> mau[i] >> d[i];

    setup(1);
    cout <<n*c-res;
}
