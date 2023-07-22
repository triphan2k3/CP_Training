#include <bits/stdc++.h>
using namespace std;
long long c,n,a[18];
bool f[5002];
int main()
{
    cin >> c >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    f[0]=true;
    for (int i=1;i<=n;i++)
        for (int j=c;j>=0;j--)

        if (j>=a[i]) f[j]=f[j-a[i]] || f[j];


    int res=0;
    for (int i=1;i<=c;i++)
        if (f[i]==true) res=i;
    cout << res;
}
