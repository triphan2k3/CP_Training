#include <bits/stdc++.h>
using namespace std;

const int Nmax=100002;
long l[Nmax],r[Nmax],s[Nmax],a[Nmax];

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        l[i]=min(l[i-1],s[i]);
    }
    long t;
    for (int i=n;i>=1;i--)
    {
        t=s[n]-s[i-1];
        r[i]=max(r[i+1],t);
    }
    int res=0;
    for (int i=1;i<=n;i++)
        if (s[n]-s[i-1]+l[i-1]>0 && s[n]-s[i-1]-r[i+1]>0) res++;

    cout << res;

}
