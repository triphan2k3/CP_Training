#include <bits/stdc++.h>
using namespace std;
const int Nmax=100000;
int l[Nmax+1],r[Nmax+1],s[Nmax+1],a[Nmax+1],ma;

int npl(int i)
{
    int l=0,r=ma;
    do
    {
        int m=(l+r)/2;
        if (a[s[m]]>=a[i]) r=m;
        else l=m;
    } while (r-l>1);
    if (a[s[r]]<a[i]) l=r;
    if (ma<l+1)
    {
        ma++;
        s[ma]=i;
    } else if (a[s[l+1]]>a[i]) s[l+1]=i;
    return l+1;
}

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
        l[i]=npl(i);

    ma=0;
    for (int i=n;i>=1;i--)
        r[i]=npl(i);
    int res=1;
    for (int i=1;i<=n;i++)
    {
        int t=2*min(l[i],r[i])-1;
        res=max(res,t);
    }
    cout << res;
}
