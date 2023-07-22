#include <bits/stdc++.h>
using namespace std;
const int Nmax=30000;
int ma,s[Nmax+1],res[Nmax+1];
long a[Nmax+1];

int np(long i)
{
    int l=0,r=ma;
    do
    {
        int m=(l+r)/2;
        if (a[s[m]]>=a[i]) r=m;
        else l=m;
    } while ((r-l)>1);
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
    s[0]=0;

    for (int i=1;i<=n;i++)
        res[i]=np(i);

    cout << ma;

}
