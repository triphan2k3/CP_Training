#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int m,n;
int main()
{
    //ifstream f ("test.inp");
    cin >> m >> n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        cin >> a[i][j];

    for (int i=1;i<=n;i++)
        a[0][i]=a[m+1][i]=-100000;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[j][i]+=max(a[j-1][i-1],max(a[j][i-1],a[j+1][i-1]));
    int res=-100000;
    for (int i=1;i<=m;i++) res=max(res,a[i][n]);
    cout << res;
}
