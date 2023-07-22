#include <bits/stdc++.h>
#define ma 60003
using namespace std;
long long f[ma],n,k,a[ma],r[ma];
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        cin>> a[i];
    for (int i=2;i<=n;i++)
        cin>> r[i];
    //ri la thang i-1 mua cho no vs mua cho i
    f[1]=a[1];
    f[2]=min(r[2],a[1]+a[2]);

    for (int i=3;i<=n;i++)
        f[i]=min(f[i-1]+a[i],f[i-2]+r[i]);

    cout << f[n];
}
