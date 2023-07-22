#include <bits/stdc++.h>
using namespace std;
const long inf=1e9+1;
long a[100001];
int s[100001],ma,n;

void np(int i)
{
    int l=0,r=ma;
    do
    {
        int m=(l+r)/2;
        if (a[s[m]]<=a[i]) r=m;
        else l=m;
    } while (r-l>1);
    if (a[s[r]]>a[i]) l=r;
    if (l+1>ma)
    {
        ma++;
        s[ma]=i;
    } else if (a[s[l+1]]<a[i]) s[l+1]=i;
}
int main()
{
    cin >> n;
    a[0]=inf;
    ma=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        np(i);
    }
    cout << ma;
}
