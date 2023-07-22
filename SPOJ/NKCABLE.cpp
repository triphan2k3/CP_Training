#include <bits/stdc++.h>
using namespace std;
long f[25001],n,a[25001];
int main()
{
    cin >> n;
    if (n==1)
    {
        cout << 0;
        return 0;
    }
    for (int i=2;i<=n;i++)
        cin >> a[i];
    f[1]=10000000;
    f[2]=a[2];
    for (int i=3;i<=n;i++)
        f[i]=min(f[i-1]+a[i],f[i-2]+a[i]);
    cout << f[n];
}
