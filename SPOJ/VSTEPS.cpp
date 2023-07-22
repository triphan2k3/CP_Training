#include <bits/stdc++.h>
#define md 14062008
using namespace std;
long ck[100001],f[100001],n,k;

int main()
{
    cin >> n >> k;
    for (int i=1;i<=k;i++)
    {
        int temp;
        cin >> temp;
        ck[temp]=1;
    }

    f[1]=1;

    for (int i=2;i<=n;i++)
        if (ck[i]==0) f[i]=(f[i-1]+f[i-2])% md;

    cout << f[n];
}
