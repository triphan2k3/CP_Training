#include <bits/stdc++.h>
using namespace std;
int n,res,a[5001],f[5001][5001];
int main()
{
    //ifstream g ("test.inp");
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        f[i][j]=1;
        if (a[i]-a[i-1]==a[j]-a[j-1])
        {
            f[i][j]=min(j-i,f[i-1][j-1]+1);
            res=max(res,f[i][j]);
        }
    }

    if (res>=5) cout<< res;
    else cout << 0;
}
