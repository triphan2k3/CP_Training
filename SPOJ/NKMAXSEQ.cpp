#include <bits/stdc++.h>
using namespace std;

bool d[50001];
long a[50001],f[50001],p;

int main()
{
    int n;
    cin >> n >>p;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    int mi=0,s=0;

    for (int i=1;i<=n;i++)
    {
        f[i]=a[i]+f[i-1];
        if (f[i]<mi)
        {
            d[i]=true;
            mi=f[i];
        }
    }
    d[0]=true;
    int res=-1;
    int pos=n;
    for (int i=n;i>=0;i--)
        if (d[i])
    {
        for (int j=pos;j>=i;j--)
            if (f[j]-f[i]>=p)
        {
            res=max(res,j-i);
            pos=j;
            break;
        }
    }
    cout << res;
}
