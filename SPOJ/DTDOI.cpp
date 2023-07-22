#include <bits/stdc++.h>
using namespace std;
long a[102],f[2000],n,s;
const long inf=1e9+1;
int main()
{
    cin >> n >> s;
    long ma=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        ma=max(ma,a[i]);
    }

    for (int i=1;i<=1100;i++)
    {
        f[i]=inf;
        for (int j=1;j<=n;j++)
        if (a[j]<=i) f[i]=min(f[i],f[i-a[j]]+1);
    }
    if (s<=1100)
    {
        cout <<f[s];
        return 0;
    }
    long temp=(s-1100)/ma+1;
    s-=temp*ma;
    cout << temp+f[s];
}
