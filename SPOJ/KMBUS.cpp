#include <bits/stdc++.h>
using namespace std;
const long inf=1e9;
long f[20000];
int b,l,c[200];
int main()
{
    //ifstream ff ("test.inp");
    cin >> b >> l;
    //ff >> b >> l;
    for (int i=1;i<=b;i++)
        cin >> c[i];
        //ff >> c[i];

    for (int i=1;i<=l;i++)
    {
        f[i]=inf;
        for (int j=1;j<=min(i,b);j++)
        f[i]=min(f[i],f[i-j]+c[j]);
    }
    cout << f[l];
    //ff.close();
}
