#include <bits/stdc++.h>
using namespace std;
int sum[21],a[21][21],s,k,n,res[21];
bool kt=false;

void tryy(int i)
{

        if (i==k+1)
        {
            if (sum[i-1]==s)
                kt=true;
            return;
        }
        for (int j=1;j<=n;j++)
        if (a[i][j]>=res[i-1])
        {
            sum[i]=sum[i-1]+a[i][j];
            if (i==k)
            {
                res[i]=a[i][j];
                if (sum[i]==s)
                kt=true;
                return;
            }
            if ( s >= a[i][j]*(k-i)+sum[i])
            {
                res[i]=a[i][j];
                tryy(i+1);
                if (kt==true) return;
            }
        }
}
int main()
{
     cin >> s >> k >> n;  // k la so bai n la so nguoi

    for (int i=1;i<=n;i++)
    for (int j=1;j<=k;j++)
    cin >> a[j][i];
    sum[0]=0;
    tryy(1);
    if (kt==true)
    {
        cout<<"YES"<< endl;
        for (int i=1;i<=k;i++)
        cout<< res[i] <<' ';
    } else
    cout<<"NO";
}
