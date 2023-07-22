#include <bits/stdc++.h>
using namespace std;

int n,f[2][2],a[2],b[2];
int main()
{
    cin >> n;
    cin >> a[1] >> b[1];
    f[1][0]=b[1];
    f[1][1]=a[1];
    for (int i=2;i<=n;i++)
    {
        cin >> a[i%2] >> b[i%2];
        f[i%2][0]=max(f[(i+1)%2][0]+abs(a[i%2]-a[(i+1)%2])+b[i%2],
                      f[(i+1)%2][1]+abs(a[i%2]-b[(i+1)%2])+b[i%2]);

        f[i%2][1]=max(f[(i+1)%2][0]+abs(b[i%2]-a[(i+1)%2])+a[i%2],
                      f[(i+1)%2][1]+abs(b[i%2]-b[(i+1)%2])+a[i%2]);
    }
    cout << max(f[n%2][0],f[n%2][1]);
}
