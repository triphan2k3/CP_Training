#include <bits/stdc++.h>
using namespace std;
int m,n,f[1003][1003],a[1003],b[1003];
int main()
{
    cin >> m >> n;
    m++;
    n++;
    for (int i=2;i<=m;i++)
        cin >> a[i];

    for (int i=2;i<=n;i++)
        cin >> b[i];

    for (int i=2;i<=m;i++)
        for (int j=2;j<=n;j++)
        f[i][j]=(a[i]==b[j]) ? f[i-2][j-2]+1 : max(f[i][j-1],f[i-1][j]);

    cout << f[m][n];
}
