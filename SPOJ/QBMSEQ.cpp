#include <bits/stdc++.h>
using namespace std;
int f[10001];
long a[10001];
int n,res;

bool check(long x)
{
    if (x==1) return (true);
    long temp=sqrt(x*2);
    return (temp*(temp+1)/2==x || (temp*(temp-1)/2==x));
}
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
        if (check(a[i]))
        {
            f[i]=(a[i]>=a[i-1]) ? f[i-1]+1 : 1;
            res=max(res,f[i]);
        }
    cout << res;


}
