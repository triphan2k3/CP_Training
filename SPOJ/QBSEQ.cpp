#include <bits/stdc++.h>
using namespace std;

const int Nmax=1002;
int f[Nmax][50],a[Nmax];
bool ck[Nmax][50];

int main()
{
    int n,k;

    cin >> n >> k;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    ck[0][0]=true;
    for (int i=1;i<=n;i++)
        for (int j=0;j<k;j++)
        {
            int t=(j-a[i])%k;
            if (t<0) t+=k;
            ck[i][j]=ck[i-1][j];
            f[i][j]=f[i-1][j];
            if  (ck[i-1][t])
            {
                f[i][j]=max(f[i][j],f[i-1][t]+1);
                ck[i][j]=true;
            }
        }

    cout << f[n][0];
}
